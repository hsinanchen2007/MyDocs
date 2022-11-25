// Root2.cpp
// --------------------------------------
#include <iostream>
#include <cmath>
using namespace std;
// ------ 主程式 --------------------
int main()
{	
	float a, b, c, D;
	cout << "請輸入 a:" << endl;
	cin >> a;
	cout << "請輸入 b:" << endl;
	cin >> b;
	cout << "請輸入 c:" << endl;
	cin >> c;
	if ( a == 0.0 )
		if (b==0.0)
			cout << "無解! " << endl;
		else
			cout << "只有一組解: " << -c/b << endl;
	else
	{
		D= b*b-4.0*a*c;
		if (D==0.0)
			cout << "重根: "  
			<< -b/(2.0*a) << endl;
		else if (D>0.0)
		{
			cout << "有兩組實數解"      << endl;
			cout << "第一組:"  
				<< (-b+sqrt(D))/(2.0*a) << endl;
			cout << "第二組:"  
				<< (-b-sqrt(D))/(2.0*a) << endl;
		}
		else
		{
			cout << "解為兩組共軛複數"      << endl;  	
			cout << "第一組:"   
				<< (-b)/(2.0*a)
				<< " + i " << sqrt(-D)/(2.0*a) 
				<< endl;
			cout << "第二組:"   
				<< (-b)/(2.0*a)
				<< " - i " << sqrt(-D)/(2.0*a) 
				<< endl;
		}
	}
	system("pause");
	return 0;
}

