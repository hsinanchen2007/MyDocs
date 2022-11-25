// 标识号类IdNo（第1版：头文件）

#ifndef ___Class_IdNo
#define ___Class_IdNo

//===== 标识号类 =====//
class IdNo {
	static int counter;		// 已经赋予的标识号数量
	int id_no;				// 标识号

public:
	IdNo();					// 构造函数

	int id() const;			// 返回标识号
};

#endif
