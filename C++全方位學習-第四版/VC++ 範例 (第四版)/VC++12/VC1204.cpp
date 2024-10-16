//檔案名稱：d:\VC++12\VC1204\VC1204.cpp
#include <iostream>
using namespace std;

class Cuboid	//宣告長方體類別
{
private:
	int length;	//Cuboid的資料成員1
	int width;	//Cuboid的資料成員2
	int height;	//Cuboid的資料成員3
public:
	Cuboid(int l, int w)	//長方形邊長建立者
	{
		length = l;
		width = w;
		height = 0;
	}
	Cuboid(int l, int w, int h)	//長方體邊長建立者
	{
		length = l;
		width = w;
		height = h;
	}
	int area()	//計算面積或表面積函數
	{
		return 2 * (length * width
			+ width * height
			+ height * length);
	}
};

int main(int argc, char** argv)
{
	Cuboid rt(6, 8);	//建立並起始rt物件資料
	Cuboid cb(6, 8, 10);	//建立並起始cb物件資料

	cout << "長方形面積 = " << rt.area();	//輸出長方形面積
	cout << "平方公分\n";
	cout << "長方體表面積 = " << cb.area();	//輸出長方體表面積
	cout << "平方公分\n";
	return 0;
}
