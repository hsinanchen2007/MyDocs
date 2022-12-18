/*

https://www.educative.io/module/lesson/oop-in-cpp/B186jA6BR02

If we want to inherit data members and member functions of the base class which 
is already inherited from another class, the concept of multilevel inheritance 
comes in. This contains a more hierarchical approach.

    class parent
    class child : public parent
    class grandChild : public child

Example
Let’s take the example of Vehicle class which acts as a parent to Car class. 
Now Car class acts as a parent to Honda class.

*/

#include <iostream>
#include <string>

using namespace std;

class Vehicle {
  protected:
  string Make;
  string Color;
  int Year;
  string Model;

  public:
  Vehicle(){
    Make = "";
    Color = "";
    Year = 0;
    Model = "";
  }

  Vehicle(string mk, string col, int yr, string mdl){
    Make = mk;
    Color = col;
    Year = yr;
    Model = mdl;
  }

  void print_details(){
    cout << "Manufacturer: " << Make << endl;
    cout << "Color: " << Color << endl;
    cout << "Year: " << Year << endl;
    cout << "Model: " << Model << endl;
  }
};

class Car: public Vehicle{
  string trunk_size;

  public:
  Car(){
    trunk_size = "";
  }

  Car(string mk, string col, int yr, string mdl, string ts)
    :Vehicle(mk, col, yr, mdl){
      trunk_size = ts;
    }

  void car_details(){
    cout << "Trunk size: " << trunk_size << endl;
  }
};

class Honda: public Car{
  int top_speed;

  public:
  Honda(){
    top_speed = 0;
  }

  Honda(string mk, string col, int yr, string mdl, string na, int ts)
    :Car(mk, col, yr, mdl, na){
      top_speed = ts;
    }

  void Honda_details(){
    print_details();
    car_details();
    cout << "Top speed of the car: " << top_speed << endl;
  }
};

int main(){
  Honda car("Honda", "Black", 2006, "Accord", "14.7 cubic feet", 260);
  car.Honda_details();
}

