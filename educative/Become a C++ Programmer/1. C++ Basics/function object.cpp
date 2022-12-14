/*

https://www.educative.io/module/lesson/cpp-basics/7DG6JRGgqlQ

Function vs. function object 
The first thing we need to know is that lambdas are just function objects automatically 
created by the compiler.

A function object is an instance of a class for which the call operator, operator (), is 
overloaded. This means that a function object is an object that behaves like a function. 
The main difference between a function and a function object is that a function object is 
an object and can, therefore, have a state.

Instances of the struct, AddObj, and the function, addFunc, are both callable. I just defined 
the struct AddObj in place. That is what the C++ compiler does implicitly if I use a lambda 
expression. Have a look.

    int addFunc(int a, int b){ return a + b; }

    int main(){
        
        auto addObj = [](int a, int b){ return a + b; };
        
        addObj(3, 4) == addFunc(3, 4);
        
    }

That’s all! If the lambda expression captures its environment and therefore has a state, 
the corresponding struct, AddObj, gets a constructor for initializing its members. If the 
lambda expression captures its argument by reference, so does the constructor. The same 
holds for capturing by value.

*/

#include <iostream>

int addFunc(int a, int b){ return a + b; }

int main(){
    
    struct AddObj{
        int operator()(int a, int b) const { return a + b; }
    };
    
    AddObj addObj;
    if (addObj(3, 4) == addFunc(3, 4)) std::cout << "Same" << std::endl;

}

