//儲存檔名：d:\C++06\C0616.h

double degree(void)	//溫度轉換函數
{
	extern double c;	//宣告外部變數
	double f;	//宣告區域變數
	f = ((9 * c ) / 5) + 32;	//攝氏轉成華氏
	return f;	//傳回f給呼叫敘述
}