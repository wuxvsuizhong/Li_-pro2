#include <iostream>
namespace
{
  int ice;
  int bandycoot;
}

static int count;
int other();



extern void modulefunc();
int main(int argc, char const *argv[])
{

  std::cout<<"ice:"<<ice<<" count "<< count<<std::endl;
  other();
  std::cout<<"ice:"<<ice<<" count "<< count<<std::endl;

  std::cout<<"Calling modulefunc in other file...\n";
  modulefunc();
  return 0;
}

int other()
{
  std::cout<<"func other"<<std::endl;
  ice+=1,count+=1;
}