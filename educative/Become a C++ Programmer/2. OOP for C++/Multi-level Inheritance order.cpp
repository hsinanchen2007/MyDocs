/*

https://www.educative.io/module/lesson/oop-in-cpp/B186jA6BR02

f we want to inherit data members and member functions of the base class which 
is already inherited from another class, the concept of multilevel inheritance 
comes in. This contains a more hierarchical approach.

    class parent
    class child : public parent
    class grandChild : public child

Example
Let’s take the example of Vehicle class which acts as a parent to Car class. 
Now Car class acts as a parent to Honda class.

Class A defines two functions, init() and update(). Class B is derived from 
class A and defines its own update() function. Class C is derived from class 
B and does not define any function.

The call to init() for an instance of C on line 26 results in a lookup of a 
matching function in C. Since that is not found, a matching function is looked 
up in B. Since one is not found, the lookup is performed in A and a match is 
found. That is why we see Class A initialized! on the console.

Similarly, when update() is called on line 27, a matching function is not found 
in C, so it is looked up in B. A match is found in B and the call resolves, 
resulting in Class B updated! on the console. The lookup proceeds no further.

Note that this is all happening at compile time. The function calls init() and 
update() in main() are bound to appropriate function definitions at compile time.

*/

#include <iostream>
using namespace std;

class A {
  public:
    void init() {
      cout << "Class A initialized!" << endl;
    }
    void update() {
      cout << "Class A updated!" << endl;
    }
};

class B : public A {
  public:
    void update() {
      cout << "Class B updated!" << endl;
    }
};

class C : public B { };

int main() {
  // your code goes here
  C c;
  c.init();
  c.update();
  return 0;
}
