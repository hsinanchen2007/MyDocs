// 猜数游戏（第2版：头文件）

void initialize();			//【初始化】根据当前时刻设置随机数种子
void gen_no();				//【生成问题】用随机数生成0~max_no的值
int judge(int cand);		//【判断答案】判断cand是否为正确答案解
int input();				//【输入答案】输入0~max_no的值
bool confirm_retry();		//【确认是否继续】确认是否再试一次

extern int max_no;			// 要猜的数的最大值