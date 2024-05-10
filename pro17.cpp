#include <iostream>
using namespace std;
 
class Shape{
  int dimension1;
  int dimension2;
  public:
    Shape(int dim1,int dim2): dimension1(dim1) , dimension2(dim2) {}
    int getDim1() const
    {
        return dimension1;
    }
    int getDim2() const
    {
        return dimension2;
    }
};
 
ostream& operator<<(ostream& out, const Shape& sh)
{
    out<<sh.getDim1()<<"\t";
    out<<sh.getDim2();
    return out;
}
int main() {
    // Write C++ code here
    Shape s(1,2);
    cout<<s;
 
    return 0;
}
