/*

https://www.educative.io/module/lesson/oop-in-cpp/qAEL4GwpV03

Solutions to the diamond problem
In the above code example, if you were to replace return ID; on line 27 with either 
return B::ID;, or return C::ID;, the program would compile and run fine. All that 
does is explicitly tell the compiler to fetch the value of the member named ID from 
class B or class C, depending on which solution you use.

However, there are still two copies of the ID member in this program. This may be OK 
for a simple program like this, but wouldn’t be acceptable in larger programs.

One solution to the diamond problem is to use virtual inheritance, as shown in the 
following program.

With virtual inheritance, only one instance of the base class A is inherited into 
the derived class D.

*/

#include<iostream>
using namespace std;
 
class A
{
protected:
    int ID;
public:
    A() : ID(0) { }
};
 
class B:  virtual public A
{
public:
    int length;
};
 
 
class C:  virtual public A
{
public:
    int radius;
};
 
class D: public B, public C
{
public:
    int getID()  {   return ID;  }
};
 
int main(void)
{
    D d;
    cout << d.getID();
    return 0;
}

