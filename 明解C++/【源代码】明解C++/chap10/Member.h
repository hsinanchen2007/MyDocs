//--- 会员类（头文件）---//

#include <string>

class Member {
	std::string full_name;	// 姓名
	int			no;			// 会员编号
	int			rank;		// 会员等级

public:
	// 构造函数【声明】
	Member(std::string name, int number, int grade);

	// 获取等级（获取器）
	int get_rank() { return rank; }

	// 设置等级（设置器）
	void set_rank(int grade) { rank = grade; }

	// 显示【声明】
	void print();
};
