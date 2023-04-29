#include "man.h"
#include <string.h>
#include <iostream>

man::man():gender(1)
{
    name = new char[1024]();
    std::cout << "man create" << std::endl;
}

man::man(int num):gender(1)
{
    std::cout << "init age num" << std::endl;
    age = num;
}


man::man(const char *namestr):gender(1)
{
    name = new char[1024]();
    if(strcmp(namestr,"") != 0){
        strcpy(name,namestr);
    }
    std::cout << "man create" << std::endl;

}

//类man的拷贝构造函数
man::man(const man &m):gender(m.get_gender())
{
    name = new char[1024]();
    strcpy(name,m.get_name());
    age = m.get_age();
//    gender = m.gender;
    std::cout << "man instance copy" << std::endl;
}

man::~man()
{
    delete []name;
}


void man::set_name(const char *namestr)
{
    int ret = strcmp(namestr,"");
    if(ret != 0)
        strcpy(name,namestr);
}

void man::set_age(const int num)
{
    age = num;
}

const char* man::get_name() const
{
    return name;
}

int man::get_age() const
{
    return age;
}

const bool man::get_gender() const
{
    return gender;
}

