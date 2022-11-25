// 幂运算

//--- 返回x的n次方 ---//
double power(double x, int n)
{
	double tmp = 1.0;

	for (int i = 1; i <= n; i++)
		tmp *= x;	// tmp乘以x
	return tmp;
}
