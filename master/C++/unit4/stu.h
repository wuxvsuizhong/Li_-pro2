#ifndef STU_H
#define STU_H


class stu
{
private:
    int age;
    char *name;
    static int num;
    static int num2;

public:
    stu();
    stu(const char* name, int age);
    ~stu();

    const int get_age();
    void set_name(const char* name);
    const char* get_name() const;

    stu* returnthis();

    void set_num(int n);
    int get_num();

    //类的静态成员函数
    static void set_num2(int n);
    static int get_num2();


};

#endif // STU_H
