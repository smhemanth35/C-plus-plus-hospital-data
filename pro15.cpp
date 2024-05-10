#include <iostream>
#include <cstring>
#include <vector>
 
using namespace std;
class PrinterMgr;   // forward declatation
class Printer
 
{
 
    Printer(): name("Hp_Printer"), code(1001) { }
 
    friend class PrinterMgr;
    string name;
    int code;
    mutable bool lock; // change the values in const method
public:
    void printFile(string docName) const
 
    {
        lock=true;
        cout<<"Printing the file "<<docName<<endl;
        lock=false;
 
    }
    void setDeviceDriver()
    {
        cout<<"Configuring the device driver."<<endl;
    }
    string getName() const
    {
        return name;
    }
    int getCode() const
    {
        return code;
    }
    //....
 
};
class PrinterMgr
 
{
 
     Printer* nwPrinter;
    static PrinterMgr* instance;
    bool inUse;
    PrinterMgr() : inUse(false) {
 
        nwPrinter = new Printer;
 
    }
    void setPrinterConfiguration(string config) 
    {
        inUse=true;
        cout<<"Config : "<<config<<endl;
        inUse=false;
    }
    friend void adminManager();
public:
 
    
    const Printer* getPrinterAccess()
 
    {
 
       const Printer *p = NULL;
 
        if(!inUse)
 
        {
 
            inUse = true;
 
        }
 
        return nwPrinter;    
 
    }

    static PrinterMgr* getInstance()
    {
        if(instance==NULL)
            instance = new PrinterMgr;
        return instance;
    }
    //.....
 
};
 
PrinterMgr* PrinterMgr:: instance;
 
void client1()
 
{
 
    const Printer* p = // new Printer;
 
        PrinterMgr::getInstance()->getPrinterAccess();
    cout<<"Printer Name: "<<p->getName()<<endl;
    cout<<"Printer Code: "<<p->getCode()<<endl;
    p->printFile("Mydoc.docx");
   // PrinterMgr:: getInstance()->setPrinterConfiguration("192.168.1.1");
 
}
void client2()
 
{
 
}
void client3()
 
{
 
}
// all these clients want access to the printer.
 
// the printer if used by another client, cannot be shared
void adminManager()
{
    PrinterMgr:: getInstance()->setPrinterConfiguration("192.168.1.1"); 
}
int main()
 
{
 
    //PrinterMgr* mgr = new PrinterMgr;
    adminManager();
    client1();
 
    return 0;
}
