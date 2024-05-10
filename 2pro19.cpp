#include <iostream>
#include <cstring>
using namespace std;
 
//Entity class : The purpose of entity class is to capture the data into a class
//The entity classess will typically map to the database tables
/* Rules:
1. All data should be private
2. Provide a default constructor
3. Incase of need for deep copy implement : Copy constructor, Operator=, and Destructor
4. Implement set and get methods
5. Make all get methods const menthods
6. Avoid pass by value and use const refernce where ever possible
*/
 
class String
{
    char *ptr;
    unsigned int length;
    //...
 
public:
    String() : ptr(NULL), length(0) {}
 
    String(const char* s)
    {
        this->length = strlen(s);
        this->ptr = new char[length + 1];
        strcpy(this->ptr, s);
        // this->ptr = const_cast<char*>(s);
 
    }
 
    String(const String &s) : length(s.length)
    {
        printf("source pointer :  %x\n", s.ptr);
        ptr = new char[length + 1];
        printf( "New memory pointer :  %x\n", this->ptr);
        strcpy(this->ptr, s.ptr);
        printf("Destination pointer :  %x\n", this->ptr);
    }
 
    const char* c_str()
    {
        return ptr;
    }
 
    // friend ostream &operator<<(ostream &out, String &s);
 
    ~String()
    {
        delete ptr;
        ptr = NULL;
        length = 0;
    }
};
 
ostream &operator<<(ostream &out, String &s)
{
    out << s.c_str();
    return out;
}
 
class Student
{
    string name;
    int age;
    double score;
 
public:
    Student(): age(0),score(0.0){}
 
    string getName() const
    {
        return this->name;
    }
 
    void setName(string name)
    {
        this->name = name;
    }
 
    int getAge() const
    {
        return this->age;
    }
 
    void setAge(int age)
    {
        this->age = age;
    }
 
    double getScore() const
    {
        return this->score;
    }
 
    void setScore(double score)
    {
        this->score = score;
    }
};
 
int main()
{
    cout << "size of string : " << sizeof(string) << endl;
    cout << "size of sring& : " << sizeof(string*) << endl;
    cout << "size of const string& : " << sizeof(const string*) << endl;
 
    String s1 = "Noor";
    cout << "s1 : " << s1 << endl;
 
    String s2 = s1;
    cout << "s2 : " << s2 << endl;
 
    String s3("Fatma");
    String s4 = "Fatma";
 
    cout << s4; // operator<<(cout, s4);
 
    // s4.operator<<(cout);
 
    return 0;
}