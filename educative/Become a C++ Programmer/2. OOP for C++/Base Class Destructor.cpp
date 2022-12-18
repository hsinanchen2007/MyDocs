/*

https://www.educative.io/module/lesson/oop-in-cpp/qADVgyXJWB2

Base Class Destructor
When we make an instance of the Derived class it will first call the destructor 
of the Derived class and then the Base class.

*/

#include <iostream> 
using namespace std; 
  
// Base class 
class Base {    
    
    public:  
    ~Base(){
      cout << endl << "Base class Destructor!" ;
    }
}; 
  
  
// Derived class 
class Derived : public Base { 
    public:  
    
    ~Derived(){
      cout << endl << "Derived class Destructor!" ;
    }
}; 
  
// main function 
int main() {    
    // creating object of Derived Class 
    Derived obj;  
} 

// Derived class Destructor!
// Base class Destructor!
