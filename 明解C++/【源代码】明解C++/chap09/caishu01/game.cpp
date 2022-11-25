// 猜数游戏（第1版：游戏部分）

#include <ctime>
#include <cstdlib>

using namespace std;

static int answer = 0;
extern int max_no;

//--- 初始化 ---//
void initialize()
{
	srand(time(NULL));
}

//--- 生成问题（要猜的数） ---//
void gen_no()
{
	answer = rand() % (max_no + 1);
}

//--- 判断答案 ---//
int judge(int cand)
{
	if (cand == answer)		// 正确答案
		return 0;
	else if (cand > answer)	// 大
		return 1;
	else					// 小
		return 2;
}
