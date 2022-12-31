// ZRK5.cpp
// --------------------------------------
#include "Common.h"
#include "ODESolve.h"
#include "MPlot.h"

int main ()
{
	Matrix Answer(SysOrder,NoPoint);
	Vector X0(SysOrder, Xi);
	Vector Xf(SysOrder);
	double LocalError;
	char ch;
	cout << "\nFifth-Order Runge-Kutta Method\n"<< endl;
	Answer = RungeKutta5(X0, LocalError, ODESystem);
	cout << " The max. local truncation error is:  "
		<< setiosflags(ios::scientific)
		<< setprecision(8)
		<< LocalError << endl;

	// Display results
	Xf = Answer.PickCol(1);
	cout << " The initial value is:  " << endl;
	Xf.Display();
	Xf = Answer.PickCol(NoPoint);
	cout << " The final value is  :  "  << endl;
	Xf.Display();
	cout << " 要不要將結果存成 M-file? (y/n)\n"
		<< endl;
	cin >> ch;
	if (ch=='y')
	{
		XYPlot (Answer);
		TXPlot (Answer);
	}
	else
		cout << " 沒有存檔.\n"  << endl;
}
/*

Fifth-Order Runge-Kutta Method

The max. local truncation error is:  0
The initial value is:
2.0000      0.5000
The final value is  :
0.3025      1.0620
要不要將結果存成 M-file? (y/n)
y
成功存於 XYPlot.m
成功存於 TXPlot.m


*/