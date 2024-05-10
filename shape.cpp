#include<iostream>
#include <cstring>
using namespace std;
 
#define TRIANGLE 1
#define RECTANGLE 2
#define SQUARE 3
 
class Shape;
 
class AbstractRenderer  
{
    protected:
        Shape *shape;
    public:
        AbstractRenderer(Shape *s) : shape(s) {}
        virtual ~AbstractRenderer() 
        {
            cout<<"~AbstractRenderer()"<<endl;
        }
        virtual void draw() = 0;
        virtual string getType() = 0;
};
 
class RendererFactory {
  public:
    static AbstractRenderer* create(Shape *shape, int type);
};
 
 
class Shape{
 
    protected:
      double dimension1;  
      double dimension2;  
      AbstractRenderer *renderer;
  public:
    Shape() : dimension1(0), dimension2(0) {
        setRenderer(1);
    }
    Shape(double _dimension1, double _dimension2) : dimension1(_dimension1), dimension2(_dimension2)
    {
        setRenderer(1);
    }
    virtual double area() = 0;
    virtual ~Shape() {
        cout<<"~Shape()"<<endl;
        delete renderer;
    }
    virtual string getType() {
        return "Shape Undefined";
    }
    void setDimensions(double _dimension1, double _dimension2)
    {
        dimension1 = _dimension1;
        dimension2 = _dimension2;
    }
    void setRenderer(int type){
        this->renderer = RendererFactory::create(this, type);
    }
    void draw(){
        renderer->draw();
    }
    friend ostream &operator<<(ostream &out, const Shape &s);
};
 
 
 
 
class TwoDRenderer : public AbstractRenderer {
    public:
        TwoDRenderer(Shape *s) : AbstractRenderer(s) {} 
        string getType(){
            return "2 D Renderer";
        }
        void draw(){
            cout<<"Drawing "<<shape->getType()<<" in 2-D "<<endl;
        }
        ~TwoDRenderer() {
            cout<<"~TwoDRenderer()"<<endl;
        }
};
class ThreeDRenderer : public AbstractRenderer {
    public:
        ThreeDRenderer(Shape *s) : AbstractRenderer(s) {} 
        string getType(){
            return "3 D Renderer";
        }
        void draw(){
            cout<<"Drawing "<<shape->getType()<<" in 3-D "<<endl;
        }
        ~ThreeDRenderer() {
            cout<<"~ThreeDRenderer()"<<endl;
        }
};
 
 
AbstractRenderer* RendererFactory::create(Shape *shape, int type){
    if(type == 2){
        return new ThreeDRenderer(shape);
    }else{
        return new TwoDRenderer(shape);
    }
    return NULL;
}
 
class Triangle : public Shape {

public:
    Triangle() { }
    Triangle(double base, double height) : Shape(base, height) { }
    double area(){
        return 0.5 * dimension1 * dimension2;
    }
    string getType() {
        return "Triangle";
    }
    ~Triangle(){
        cout<<"~Triangle()"<<endl;
    }
};
 
class Rectangle : public Shape {
public:
    Rectangle() { }
    Rectangle(double length, double breadth) : Shape(length, breadth) { }

    double area(){
        return dimension1 * dimension2;
    }
     string getType() {
        return "Rectangle";
    }
    ~Rectangle(){
        cout<<"~Rectangle()"<<endl;
    }
};
 
class Square : public Shape {
public:
    Square() { }
    Square(double side) : Shape(side, side) { }

    double area(){
        return dimension1 * dimension2;
    }
    string getType() {
        return "Square";
    }
    ~Square(){
        cout<<"~Square()"<<endl;
    }
};
 
 
class ShapeFactory {
    ShapeFactory() {}
    static ShapeFactory *instance; 
    public:
        static ShapeFactory* getInstance()
        {
            if(instance == NULL){
                instance = new ShapeFactory;
            }
            return instance;
        }
        Shape* createShape(int type){
            Shape *s = NULL;
            switch(type){
                case TRIANGLE: s = new Triangle; break;
                case RECTANGLE: s = new Rectangle; break;
                case SQUARE: s = new Square; break;
            }
            return s;
        }
};
 
 
ShapeFactory* ShapeFactory::instance = NULL;
 
 
ostream &operator<<(ostream &out, const Shape &s)
 
{
    out << s.dimension1 << endl;
    out << s.dimension2 << endl;
    out << endl;
    return out;
}
 
class Client {
  public:
    void execute(){
        Shape *shape = ShapeFactory::getInstance()->createShape(TRIANGLE);
        shape->setDimensions(20, 30);
        cout<<"Type of Shape : "<<shape->getType()<<endl;
        cout<<"Dimensions of The Shape : "<<endl<< *shape;
        cout<<"Area of Shape : "<< shape->area() <<endl;
        shape->setRenderer(2);
        shape->draw();
        delete shape;
    }
};
int main(){
    Client *client = new Client;
    client->execute();

    return 0;
}