// FEClass.h
// --------------------------------------
#ifndef FECLASS_H
#define FECLASS_H

#include <iostream>
using namespace::std;

//---- 宣告類別 Elevator--------
class Elevator
{ 
  friend void Call(Elevator&, int);
  friend void Select(Elevator&, int);
  public:    
    Elevator(); // 預設建構函數
    Elevator(int); // 建構函數(可設定初值)
    ~Elevator();  // 解構函數
    static int Count; // static 變數
  private:    
    int  CurrentFloor;    
    void Move(int);
};

#endif