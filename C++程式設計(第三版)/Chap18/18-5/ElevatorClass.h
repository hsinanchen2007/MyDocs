// ElevatorClass.h
// --------------------------------------
#ifndef ELEVATORCLASS_H
#define ELEVATORCLASS_H

#include <iostream>
using namespace::std;

//---- 宣告類別 Elevator--------
class Elevator
{ 
	private:    
		int  CurrentFloor;    
		void Move(int);
	public:
		Elevator(); // 預設建構函數
		Elevator(int); // 建構函數(可設定初值)
		~Elevator();  // 解構函數
		void Call(int);
		void Select(int);
		static int Count; // static 變數
};

#endif