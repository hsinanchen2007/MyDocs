/*

https://www.educative.io/module/lesson/oop-in-cpp/xlP6ryMMEmJ

public Mode of Inheritance
By using public inheritance, the private members of the base class are inaccessible 
in the derived class and in main. Protected members of the base class are accessible 
to the derived class but not in main. Public members of the base class are accessible 
to the derived class and in main.

*/

class Vehicle{
  
  string Make;
  string Color;
  int Year;
  
  protected:
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
    cout << "Model: " << Model << endl;  // Model is protected and 
    // is accessible in derived class
  }
};

int main(){
  Car car("Chevrolet", "Black", 2010, "Camaro", "9.1 cubic feet");
  // car.Year = 2000;     // this will give error as Year is private
   //car.Model = "Accord";   // this will give error as Model is protected
  
  car.car_details();
  car.print_details();   // public functions of base class are accessible in main
}
