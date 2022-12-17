/*

https://www.educative.io/module/lesson/oop-in-cpp/JYxx7O662Jo

NOTE: The following code 85 ~ 104 generates an error and the reasons why are mentioned below

*/

#include <iostream>

class NonCopyableClass{
  public:

    // state the compiler generated default constructor
    NonCopyableClass() = default;

    /* 
        In lines 21 to 27, we have disabled copy operations for NonCopyableClass but enabled 
        move operation. By assigning delete, we tell the compiler that the operation will not 
        be accepted. Hence, an error will be thrown. 
        With delete, we can also prevent objects from being created on the heap or stack.
    */

    // disallow copying
    NonCopyableClass& operator = (const NonCopyableClass&) = delete;
    NonCopyableClass (const NonCopyableClass&) = delete;
    
    // allow moving
    NonCopyableClass& operator = (NonCopyableClass&&) = default;
    NonCopyableClass (NonCopyableClass&&) = default;
};


class TypeOnStack {
  public:
    /*
        In the TypeOnStack class, we assign delete to the operator new on line 40. 
        This means that an object of this class cannot occupy space on the heap.
        To make a class on stack. "new" keyword is not allowed to call
    */
    void * operator new(std::size_t) = delete;
};

class TypeOnHeap{
  public:
    /*
        Conversely, the TypeOnHeap class is not allowed to make objects on the stack. 
        We simply define a destructor that calls delete in line 49.
        To make a class on the heap, "new" keyword is used when it is declared.
    */
    ~TypeOnHeap() = delete;
};

/*
    Lastly, there is the onlyDouble() function. We have explicitly told the compiler 
    to accept only double arguments.
    For any other arguments, onlyDouble() will generate an error.
*/
void onlyDouble(double){}
template <typename T>
void onlyDouble(T) = delete;

int main(){

    /*
        line 15, default constructor without any argument, copy or move
    */
    NonCopyableClass nonCopyableClass;

    /*
        line 40, below statement didn't have "new" at all to make it stays on stack
    */
    TypeOnStack typeOnStack;

    /*
        line 49, below statement has "new" to make it stays on heap
    */
    TypeOnHeap * typeOnHeap = new TypeOnHeap;

    /*
        line 57, it allows double argument
    */
    onlyDouble(3.14);

    // force the compiler errors
    /*
        line 25 ~ 26, class specifies no copy operation
    */
    NonCopyableClass nonCopyableClass2(nonCopyableClass); // cannot copy

    /*
        line 40, class specifies no "new" operation
    */
    TypeOnStack * typeOnHeap2 = new TypeOnStack; // cannot create on heap

    /*
        line 51, it needs to use "new" to stay on heap
    */
    TypeOnHeap typeOnStack2; // cannot create on stack

    /*
        line 60 ~ 61, all other the argument types not double are now allowed
    */
    onlyDouble(2011); // int argument not accepted
}
