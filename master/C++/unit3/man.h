#ifndef MAN_H
#define MAN_H

class classman
{
private:
   char name[100];
   int age;
   const bool gender;
   bool isworker;
   char* info; //在构造函数中给其分配内存空间,在析构函数中释放其空间
public:
   classman();
   classman(const char* namestr,bool isworker=true);  //构造函数的默认参数,默认参数在头文件.h中成员函数定义的地方设置
//   classman(bool isworker=true);   默认参数和不带入参的构造函数会有二义性
   ~classman();
   void set_name(const char* namestr);
   void set_age(int n);

   const char* get_name();
   const int get_age();

   char* get_info();
};



#endif // MAN_H
