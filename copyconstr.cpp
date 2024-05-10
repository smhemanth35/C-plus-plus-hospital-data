#include <iostream>
// This line includes the iostream header file, which allows input and output operations using streams (like cin and cout).

using namespace std;
// This line tells the compiler to use the std namespace, which includes many standard C++ functions and objects.

class A
{
    int a, b;
public:
    // Constructor that takes two integers and initializes a and b.
    A(int x, int y)
    {
        a = x; // Assign the value of x to member variable a.
        b = y; // Assign the value of y to member variable b.
    }

    // Copy constructor that copies values from an existing object.
    A(A &ref)//A(1) was giving reference from A using & operator that stored in ref
    {
        a = ref.a; // New object's a (1st object's a) gets the value of old object's a (last object's a).
        b = ref.b; // New object's b (1st object's b) gets the value of old object's b (last object's b).
    }

    // Member function to display the values of a and b.
    void show()
    {
        cout << a << " " << b << endl; // Display the values of a and b separated by a space and then a newline.
    }
};

int main()
{
    // Creating an object obj of class A with initial values 10 and 20.
    A obj(10, 20);

    // Creating another object obj2 and initializing it with obj (invokes the copy constructor).
    A obj2 = obj;

    // Displaying the values of a and b for the obj object using the show() member function.
    obj.show();

    // Displaying the values of a and b for the obj object again using the show() member function.
    obj.show();

    return 0;
}
