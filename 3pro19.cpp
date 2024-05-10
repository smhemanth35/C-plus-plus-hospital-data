#include <iostream>
#include <string>
using namespace std;
 
class A 
{
public:
    A() { cout<<"A()"<<endl; }
    A(A& a) { cout<<"A(A&)"<<endl; }
    A& operator=(const A& a) 
    {
        cout<<"op=(A&)"<<endl;
        return *this;
    }
    ~A() { cout<<"~A()"<<endl; }
};
 
class B 
{
public:
    B() { cout<<"B()"<<endl; }
    B(B& b) { cout<<"B(B&)"<<endl; }
    B& operator=(const B& b) 
    {
        cout<<"op=(B&)"<<endl;
        return *this;
    }
    ~B() { cout<<"~B()"<<endl; }
};
 
class C
{
    A a;
    B b;
public:
    C() { 
        cout<<"C()"<<endl; }
    C(C& c) { cout<<"C(C&)"<<endl; }
    C& operator=(const C& c) 
    {
        cout<<"op=(C&)"<<endl;
        return *this;
    }
    ~C() { cout<<"~C()"<<endl; 
    }
};
 
int main() {
    C c1;
    C c2(c1);
    return 0;
}