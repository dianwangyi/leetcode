1. int *p[10] 与 int(*p)[10] int p(int), int (*p) (int)的区别

2. typedef define 区别
    1）define在在预编译的时候处理， typedef在编译的时候处理
    2）define不做类型的检查，只是简单的替换 typedef 定义了一个新的类型别名，有类型检查
    3）#define p_char_d char*  typedef char * p_char_t
        p_char_d a,b   p_char_t c,d
        a c d 都为char*类型， b为char类型。
    4）typedef相当于定义类型别名，宏用于定义常量与书写复杂的内容

3. 变量声明与定义
    1）变量定义为变量分配存储空间，并可以指定初始值，程序中变量只能有一次定义，分配内存
    2）声明：向程序表明变量的类型和名字，不分配内存
    3）定义也是声明，extern用于声明变量而不定义它，
    4）对变量除非有extern 关键字，不然都为定义， 对函数，没有{}为声明； 

4. sizeof 与 strlen
    1）sizeof为操作符，在编译时得到结果，不能进行动态分配  参数可以是任何数据或任何类型
    2）strlen为字符处理的库函数，在运行时计算， 其参数只能是以'\0'结尾的字符串

5. 指针常量 常量指针
    1）指向常量的指针，const int *p 从右向左读，   表示不能通过该指针来改变变量的值，其他指向该变量的指针可以
    2) 指针本身为常量， int * const p， 必须在定义的同时初始化