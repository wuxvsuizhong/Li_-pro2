/*
一个密码锁由 4 个环形拨轮组成，每个拨轮都有 10 个数字： '0', '1', '2', '3', '4',
'5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为
'9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends
包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target
代表可以解锁的数字，请给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1
。



示例 1:

输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" ->
"0202"。 注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202"
这样的序列是不能解锁的，因为当拨动到 "0102" 时这个锁就会被锁定。 示例 2:

输入: deadends = ["8888"], target = "0009"
输出：1
解释：
把最后一位反向旋转一次即可 "0000" -> "0009"。
示例 3:

输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"],
target = "8888" 输出：-1 解释： 无法旋转到目标数字且不被锁定。 示例 4:

输入: deadends = ["0000"], target = "8888"
输出：-1


提示：

1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target 不在 deadends 之中
target 和 deadends[i] 仅由若干位数字组成
*/

// 方法1：广度优先搜索BFS
#include <iostream>
#include <vector>
#include <unordered_set>
#include<queue>

using std::vector;
using std::string;
using std::unordered_set;
using std::queue;
using std::pair;


class Sulution {
  public:
    int openLock(vector<string> &deadends, string target) {
      if(target == "0000"){
        return 0;
      }
      unordered_set<string> dead(deadends.begin(),deadends.end());
      
      if(dead.count("0000"))
        return -1;

      auto num_prev = [](char x)->char {
        return (x == '0' ? '9':x-1);
      };  //往上拨动一个号码

      auto num_succ = [](char x)->char{
        return (x == '9' ? '0':x+1);
      };  //往下拨动一个号码

      auto get = [&](string& status)->vector<string>{
        vector<string> ret;
        for(int i=0;i<4;i++){
          char num = status[i];
          status[i] = num_prev(num);
          ret.push_back(status);
          status[i] = num_succ(num);
          ret.push_back(status);
          status[i] = num;
        }
        return ret;
      };
      
      queue<pair<string,int>> q;
      q.emplace("0000",0);
      unordered_set<string> seen = {"0000"};  //作为已经入队的元素的记录容器，避免对检验元素的重复入队

      while(!q.empty()){  //队列不为空就一直循环下去
        string status = q.front().first;
        int step = q.front().second;
        q.pop();
        for(auto&& next_status: get(status)){
          if(!seen.count(next_status) && !dead.count(next_status)){
            if(next_status == target)
              return step + 1;  //如果匹配到了结果，那么立即返回
            
            q.emplace(next_status,step + 1);
            seen.insert(next_status);   //已经入队列的元素做个记录，避免重复入队
          }
        }

      }

      return -1; //如果循环完成所有队列中的元素，仍然没有匹配，那么返回-1，意味着无解
    }
};

int main()
{
  using namespace std;
  vector<string> deadends = {"0201","0101","0102","1212","2002"};
  string target = "0202";

  string str,target;
  getline(cin,str);
  getline(cin,target);


  Sulution s;
  std::cout<<s.openLock(deadends,target)<<"\n";

  return 0;
}