// ExternB.cpp
// --------------------------------------
int Bp;
extern int Am;

// --- ��� Fnc1 () ���w�q  -------------
void Func1()
{
	Bp = 2;      
	Am = 8;
}

// --- ��� Fnc2 () ���w�q  -------------
void Func2()
{
	extern int An;   
	Am += 10;
	An  = 27;
}
