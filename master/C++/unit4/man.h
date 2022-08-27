#ifndef MAN_H
#define MAN_H


class man
{
private:
    char* name;
    int age;
    const bool gender;
public:
    man();
    man(const char* namestr);

    //explicit 关键字的作用,禁止=操作符调用重载的构造函数
    //explicit 修饰后的构造函数只能使用class instance_name(val)的方式如:man m(20) 这种形式去调用该构造
    explicit man(int num);

//    类的拷贝构造函数，形参是类实例的常引用
//    如果不定义类的拷贝构造函数，编译器会为类自动生成拷贝构造函数
//    但是自动生成的拷贝构造函数无法为指针类型的成员变量分配其所指向的内存，如man类中的char* name；
//    而且自动生成的拷贝构造函数只能是对普通变量的简单赋值拷贝，int=int,char=chat, int *p=int *p
//    这对于类的指针变量成员会是灾难，在拷贝的时候只是简单的把指针的值做了拷贝然后赋值，没有为其分配空间
//    如果两个man实例使用默认生成的拷贝构造函数，那么当其中一个实例释放的时候其会释放指针变量所指向的堆内存空间，而当另外一个实例也释放的时候，会把指针变量指向的内存再释放一边
//    因为浅拷贝导致的指针变量的值相同，也及时其指向了同一片地址，所以在类析构是会造成对同一片空间的重复释放，或者是在一边已经析构释放了指向的内存地址，但是在另外一边还未释放前对指针变量指向的地址进行赋值，这很不安全
    man(const man &m);

//explicit 关键字的作用是告诉编译器不要自行生成一套默认的（拷贝）构造函数，而要使用手动定义的拷贝构造


    ~man();
    void set_name(const char* namestr);
    void set_age(const int num);

//    此处是为了拷贝构造函数的正常运行
//    因为拷贝构造函数是以const类型入参，这意味着在传递的时候其传递的类变量已经转换为不可修改的常量，也成常对象，即对象中的数据不可修改
//    对于常量类型的类数据，c++在访问时需要在函数声明后添加const；

    const char* get_name() const;
    int get_age() const;
    const bool get_gender() const;
};

#endif // MAN_H
