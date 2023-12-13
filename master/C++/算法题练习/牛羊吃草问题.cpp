#include <iostream>
// #include<string>
#include<cmath>
using namespace std;

/*
给定一个正整数N表示有N分青草，有一只羊和一头牛，牛先吃，羊后吃，他两轮流吃草，不论是牛还是羊，每次吃草的数量都是4的某次方，比如1,4，16,64等。
谁先把草吃完，谁获胜。假设牛和羊都是聪明的，都想最终能赢，每次都能做出合理的的决定，给定唯一的参数N,返回谁会赢

解析：谁最后能赢，是采取适当的措施能够使得后手面临无草可吃的情况时，那么此时先吃光草的就能先赢。
N=0时，先吃草的先面临无草可吃的情况，此时先吃草的输，后吃草的赢了；
N=1时，先吃草的吃掉，那么后吃草的面临无草可吃，所以先吃草的赢
N=2时，因为每次吃草数量的限制，且每一轮必须吃草，所以先吃草的必须吃1份，后吃草的再吃一份，然后原本最开始先吃草的面临无草可吃，所以此时后吃草的赢了。。。
N=3时，同理可得先吃草的赢。
N=4时，因为吃草的都能做出明智的选择，所以，此时先吃草的吃掉4分，让后吃草的无草可吃，先手赢
N=5时，先吃草的第一次吃掉4分，然后后吃草的只能吃掉一份，那么后吃草的赢。如果先吃草的迟到4分，后吃草的吃掉1分，那么还是后吃草的赢，，所有N=5时，先吃草的一定赢

其实在N>=5以后，每次吃草的动物面对的场景无非是1~4的循环，只是谁先谁后的角色转换而已
*/


string eat_glass_winner(int N, string first) {
    string winner = "";
    if (N >= 0 && N < 5) {
        if (N == 0 || N == 2) // 后吃草的赢
            winner = (first == "羊" ? "牛" : "羊");
        else // 先吃草的赢
            winner = (first == "牛" ? "牛" : "羊");
        return winner;
    }
    float ret = (N)/log(4);
    if((int)ret == ret){ // 先吃草的赢
      winner = (first == "牛" ? "牛" : "羊");
      return winner;
    }

    // N>=5
    string second = (first == "羊" ? "牛":"羊"); //注意这里的角色转换

    int base=1;
    while (base <= N)  //先吃草的循环每一种可能性
    {
      if(eat_glass_winner(N-base,second) == first){  //传递的second是此时的吃草角色
          return first;  //一旦有满足先吃草能赢的场景，立即返回
      }
      base *= 4;
    }
    return second;  //当所有的数据都不能满足先吃草的赢的时候，此时后吃草的才能判定为赢
}

int main(int argc, char const *argv[]) {

    for (size_t i = 0; i < 100; i++) {
      cout<<i<<" "<<eat_glass_winner(i,"牛")<<"\n";
    }

    return 0;
}
