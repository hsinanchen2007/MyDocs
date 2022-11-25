// 用于验证的标识号类VerId（头文件）

#ifndef ___Class_VerId
#define ___Class_VerId

//===== 标识号类 =====//
class VerId {
	int id_no;				// 标识号

public:
	static int counter;		// 已经赋予的标识号数量

	VerId();				// 构造函数

	int id() const;			// 返回标识号
};

#endif
