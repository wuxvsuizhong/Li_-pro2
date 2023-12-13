#include <iostream>
#include "namesp.h"

namespace pers
{
  using std::cout;
  using std::cin;

  void getPerson(Person &rp)
  {
    cout<<"Enter first name:";
    cin>>rp.fame;
    cout<<"Enter last name:";
    cin>>rp.lname;
  }

  void showPerson(const Person &rp)
  {
    std::cout<<rp.lname<<", "<<rp.fame;
  }
}

namespace debts
{
  void getDebt(Debt &rd)
  {
    getPerson(rd.name); //在namesp.h中已经在名称空间debts中引用了pers的名称空间
    std::cout<<"Enter debt:";
    std::cin>>rd.amount;
  }
  void showDebt(const Debt & rd)
  {
    showPerson(rd.name);  ////在namesp.h中已经在名称空间debts中引用了pers的名称空间,这里可以直接在debts的名称空间中直接使用pers名称空间中的函数
    std::cout<<": $"<<rd.amount<<std::endl;
  }
  double sumDebts(const Debt ar[],int n)
  {
    double total = 0;
    for (int i = 0; i < n; i++)
      total += ar[i].amount;

    return total;    
  }
}