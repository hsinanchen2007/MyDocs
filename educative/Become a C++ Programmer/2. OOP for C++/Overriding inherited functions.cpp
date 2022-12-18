/*

https://www.educative.io/module/lesson/oop-in-cpp/NEzk7WZ3YXz

Overriding inherited functions
When a derived class inherits from a base class, it may choose to change some of the 
inherited functionality. This is called function overriding, since the derived class 
is overriding the functionality of the base class.

We have defined a base class to represent an Employee. Since a Manager is also an 
Employee, we have defined a class Manager that inherits from Employee. We have kept 
information that is common to all employees in the base class. A Manager also heads 
a team, so the team name is additionally placed in that class.

In the base class, we have defined two overloaded functions named display(). One of 
these takes no argument and displays all the members to the screen. The other overload 
accepts a string salutation as an argument and prepends it to the Employee's name.

In the Manager class, we want the display() method to show the team name as well, so 
we have overridden the base class functionality for display(). We want to display all 
the essential information from the base class as well as the team name, here. Instead 
of re-inventing the wheel, we have just invoked the base class display() function by 
using the base class name (Employee) with the scope resolution operator (::) on line 31.

In main(), we have instantiated a worker, a ceo and a cto using parameterized constructors 
and then called their display() functions.

An important observation
Note that calling display("Mr") on the worker object works fine. However, if you uncomment 
line number 45 and run the program again, it fails to compile. The reason is:

Overriding a function in a derived class hides all the overloads of the same function 
from the base class.

The overloaded display(string salutation) is not available to Manager class instances.

*/

#include <iostream>
using namespace std;

class Employee {
  protected:
    string name;
    int ID;
    int reportsTo;
  public:
    Employee(string name, int ID, int boss) : name(name), ID(ID), reportsTo(boss) { }
    string getName() { return name; }
    int getID() { return ID; }
    int getBoss() { return reportsTo; }
    void display() {
      cout << ID << " " << name << " reports to " << reportsTo << endl;
    }

    void display(string salutation)
    {
      cout << salutation << " ";
      display();
    }
};

class Manager : public Employee {
  protected:
    string teamName;
  public:
    Manager(string name, int ID, int boss, string teamName) : Employee(name, ID, boss), teamName(teamName) { }
    void display() {
      Employee::display();
      cout << "   Heads the team " << teamName << endl;
    }
};



int main() {
  Employee worker("John Smith", 10, 2);
  Manager ceo("Jack Hobbs", 0, 0, "Eats R Us");
  Manager cto("Elizabeth Shaw", 2, 0, "IT");
  worker.display("Mr");
  ceo.display();
  cto.display();
  //ceo.display("Mr")
  return 0;
}

// Mr 10 John Smith reports to 2
// 0 Jack Hobbs reports to 0
//    Heads the team Eats R Us
// 2 Elizabeth Shaw reports to 0
//    Heads the team IT