/*
    实际开发中，避免产生“野指针”最有效的方法，就是在定义指针的同时完成初始化操作，即便该指针的指向尚未明确，
    也要将其初始化为空指针。
    所谓“野指针”，又称“悬挂指针”，指的是没有明确指向的指针。野指针往往指向的是那些不可用的内存区域，这就意味
    着像操作普通指针那样使用野指针（例如 &p），极可能导致程序发生异常。

    C++98/03 标准中，将一个指针初始化为空指针的方式有 2 种：
    int *p = 0;
    int *p = NULL; //推荐使用
    可以看到，我们可以将指针明确指向 0（0x0000 0000）这个内存空间。一方面，明确指针的指向可以避免其成为野指针；
    另一方面，大多数操作系统都不允许用户对地址为 0 的内存空间执行写操作，若用户在程序中尝试修改其内容，则程序
    运行会直接报错。

    相比第一种方式，我们更习惯将指针初始化为 NULL。值得一提的是，NULL 并不是 C++ 的关键字，它是 C++ 为我们事先
    定义好的一个宏，并且它的值往往就是字面量 0（#define NULL 0）。

    C++ 中将 NULL 定义为字面常量 0，虽然能满足大部分场景的需要，但个别情况下，它会导致程序的运行和我们的预期不符。
    例如：
    
    #include <iostream>
    using namespace std;
    void isnull(void *c){
        cout << "void*c" << endl;
    }
    void isnull(int n){
        cout << "int n" << endl;
    }
    int main() {
        isnull(0);
        isnull(NULL);
        return 0;
    }
    程序执行结果为：
    int n
    int n

    对于 isnull(0) 来说，显然它真正调用的是参数为整形的 isnull() 函数；而对于 isnull(NULL)，我们期望它实际调用
    的是参数为 void*c 的 isnull() 函数，但观察程序的执行结果不难看出，并不符合我们的预期。

    C++ 98/03 标准中，如果我们想令 isnull(NULL) 实际调用的是 isnull(void* c)，就需要对 NULL（或者 0）进行强制
    类型转换：
    isnull( (void*)NULL );
    isnull( (void*)0 );
    如此，才会成功调用我们预期的函数（读者可自行执行此代码，观察输出结果）。

    由于 C++ 98 标准使用期间，NULL 已经得到了广泛的应用，出于兼容性的考虑，C++11 标准并没有对 NULL 的宏定义做任何
    修改。为了修正 C++ 存在的这一 BUG，C++ 标准委员会最终决定另其炉灶，在 C++11 标准中引入一个新关键字，即 nullptr。
    在使用 nullptr 之前，读者需保证自己使用的编译器支持该关键字。以 Visual Studio 和 codeblocks 为例，前者早在 
    2010 版本就对 C++ 11 标准中的部分特性提供了支持，其中就包括 nullptr；如果使用后者，读者需将其 G++ 编译器版本至少
    升级至 4.6.1（同时开启 -std=c++0x 编译选项）。

    nullptr 是 nullptr_t 类型的右值常量，专用于初始化空类型指针。nullptr_t 是 C++11 新增加的数据类型，可称为\
    “指针空值类型”。也就是说，nullpter 仅是该类型的一个实例对象（已经定义好，可以直接使用），如果需要我们完全定义出多个
    同 nullptr 完全一样的实例对象。

    值得一提的是，nullptr 可以被隐式转换成任意的指针类型。举个例子：
    int * a1 = nullptr;
    char * a2 = nullptr;
    double * a3 = nullptr;
    显然，不同类型的指针变量都可以使用 nullptr 来初始化，编译器分别将 nullptr 隐式转换成 int*、char* 以及 double* 
    指针类型。

    另外，通过将指针初始化为 nullptr，可以很好地解决 NULL 遗留的问题，比如：
*/

#include <iostream>

using namespace std;

void isnull2(void *c){
    cout << "void*c" << endl;
}

void isnull1(int n){
    cout << "int n" << endl;
}

int main() {
    isnull1(0);
    isnull1(NULL);
    isnull2(nullptr);

    return 0;
}

// int n
// int n
// void*c
