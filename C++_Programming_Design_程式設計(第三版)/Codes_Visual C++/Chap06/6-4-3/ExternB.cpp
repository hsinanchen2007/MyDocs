// ExternB.cpp
// --------------------------------------
int Bp;
extern int Am;

// --- 函數 Fnc1 () 的定義  -------------
void Func1()
{
	Bp = 2;      
	Am = 8;
}

// --- 函數 Fnc2 () 的定義  -------------
void Func2()
{
	extern int An;   
	Am += 10;
	An  = 27;
}
