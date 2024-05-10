#include <iostream>
#include <string>
using namespace std;
 
bool enable = true;
 
void trace(const char* s)
{
    if(enable)
        cout << s << endl;
}
 
class A
{
    int x;
 
public:
    A() : x(0)
    {
        trace("A()");
    }
 
    A(const A &a): x(a.x) { trace("A(A&)"); }
 
    A &operator=(const A &a)
    {
        trace("op=(A&)");
        if(this==&a)
            return *this;
 
        this->~A();
 
        this->x = a.x;
        return *this;
    }
 
    void setX(int x)
    {
        this->x = x;
    }
 
    int getX() const
    {
        return x;
    }
 
    ~A() { trace("~A()");
        x = 0;
    }
};
 
class B
{
    int y;
 
public:
    B() : y(0) { trace("B()"); }
 
    B(const B &b):y(b.y) { trace("B(B&)"); }
 
    B &operator=(const B &b)
    {
        trace("op=(B&)");
        if(this==&b)
            return *this;
 
        this->~B();
 
        this->y = b.y;
        return *this;
    }
 
    void setY(int y)
    {
        this->y = y;
    }
 
    int getY() const
    {
        return y;
    }
 
    ~B() { trace("~B()");
        y = 0;
    }
};
 
class C
{
    A a;
    B b;
 
public:
    C()
    {
        trace("C()");
    }
 
    C(const C &c) : a(c.a), b(c.b) { trace("C(C&)"); }
 
    C &operator=(const C &c)
    {
        trace("op=(C&)");
        if(this==&c)
        {
            return *this;
        }
        this->~C();
 
        this->a = c.a;
        this->b = c.b;
 
        return *this;
    }
 
    void setA(const A& a)
    {
        this->a = a;
    }
 
    A getA() const
    {
        return a;
    }
 
    void setB(const B& b)
    {
        this->b = b;
    }
 
    B getB() const
    {
        return b;
    }
 
        ~C()
    {
        trace("~C()");
    }
};
 
void display(const C& c)
{
    cout << c.getA().getX()<<"\t";
    cout << c.getB().getY()<<endl;
}
 
int main()
{
    enable = true;
 
    C c1;
 
    A a;
    a.setX(20);
 
    B b;
    b.setY(30);
 
    c1.setA(a);
    c1.setB(b);
 
    display(c1);
 
    // C c2(c1);
    // display(c2);
 
    // C c3 = c2;
    // display(c3);
 
    // C c4, c5;
    // display(c4);
    // display(c5);
 
    // c5 = c4 = c3;
    // display(c4);
    // display(c5);
 
    C c2 = c1;
    // c2 = c1;
 
    return 0;
}