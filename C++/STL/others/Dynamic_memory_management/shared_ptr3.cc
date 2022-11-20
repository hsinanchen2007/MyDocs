#include <iostream>
#include <memory>
struct Sample
{
    Sample()
    {
        std::cout << "CONSTRUCTOR\n";
    }
    ~Sample()
    {
        std::cout << "DESTRUCTOR\n";
    }
};

// function that calls the delete [] on received pointer
void deleter(Sample * x)
{
    std::cout << "DELETER FUNCTION CALLED\n";
    delete [] x;
}

int main()
{
    // Creating a shared+ptr with custom deleter
    std::shared_ptr<Sample> p3(new Sample[12], deleter);
    return 0;
}

// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// DELETER FUNCTION CALLED
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
