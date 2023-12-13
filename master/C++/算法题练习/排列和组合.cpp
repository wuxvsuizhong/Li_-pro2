// 从一组数据中提取n个数据，组成各种组合，求组合数
#include<iostream>
#include<string>
#include<vector>
#include<functional>
using namespace std;

void GetGrps(vector<int>& nums,const int len,vector<vector<int>>& res)
{ //深度搜索实现从数据中获取数据的排列和组合
  vector<bool> rec={};
  for(int i=0;i<nums.size();i++){rec.push_back(false);}

  function<void(vector<int>&,int)> inner_dep;
  vector<int> grp={};
  // vector<vector<int>> res={};
  inner_dep = [&](vector<int>& grp,int pos){    
    if(grp.size() == len){
      res.emplace_back(grp);
      return;
    }

    for(int i=pos;i!=nums.size();i++){   //注意这里的i的初始值是pos，取自传递进来的pos
    // 也就是说这里的循环的初始位置是根据传递的进来的数据pos确定的，也得就是和循环下面面的递归调用配合，促使递归遍历数据的时候不走回头路
    // 递归遍历不走回头的结果就是，得到的是n个数据的组合而非全排列
      if(rec[i] == true) continue;
      rec[i] = true;
      grp.push_back(nums[i]);
      inner_dep(grp,i+1);
      rec[i] = false;
      grp.pop_back();
    }
  };

  function<void(vector<int>&)> inner_dep2 = [&](vector<int>& grp){
    if(grp.size() == len){
      res.emplace_back(grp);
      return;
    }

    for(int i=0;i<nums.size();i++){ //如果每次都从数组从头开始遍历，那么得到的就是全排列
      if(rec[i]) continue;
      rec[i] = true;
      grp.push_back(nums[i]);
      inner_dep2(grp);
      rec[i] = false;
      grp.pop_back();
    }
  };

  // inner_dep(grp,0);  调用第一个lambda函数inner_dep得到的是嘴和数据
  inner_dep2(grp);   //调用第二个lambda函数得到的是数据的全排列
}

void GetAllSorts(vector<int>& result,vector<int>& nums)
{//递归获取全排列
  if(nums.empty()){
    for(auto& item:result) cout<<item<<" ";
    cout<<"\n";
    return;
  }
  for(int i=0;i<nums.size();i++){
    int t_n = nums[i];
    result.push_back(t_n);
    nums.erase(nums.begin()+i);
    GetAllSorts(result,nums);
    nums.insert(nums.begin()+i,t_n);  //不用每次循环都复制一份，但是记得恢复nums的数据
    result.pop_back(); //恢复result数据，以进行下一次的循环
  }

}

void GetallGrps(vector<int>& result,vector<int>& nums,int pos,int n)
{ //递归获取所有组合
  if(result.size() >= n){
    for(auto& item: result) cout<<item<<" ";
    cout<<"\n";
    return;
  }

  for(int i=pos;i<nums.size();i++){
    int t_n = nums[i];
    result.push_back(t_n);
    // nums.erase(nums.begin()+i);   //如果是只求组合，那么不需要对nums做入栈出栈操作，只需要在调用递归前传递好pos偏移即可
    GetallGrps(result,nums,i+1,n);
    result.pop_back();
    // nums.insert(nums.begin()+i,t_n); //设置好pos偏移后，就不走回头路，得到的就是组合数据
  }
}


int main()
{
  vector<int> nums={1,2,3,4,5};
  int n=3;
  
  vector<vector<int>> ret={};
  // GetGrps(nums,n,ret);
  // for(auto& item: ret){
  //   for(auto& num:item){
  //     cout<<num<<" ";
  //   }
  //   cout<<"\n";
  // }
  
  vector<int> res={};
  GetAllSorts(res,nums);
  GetallGrps(res,nums,0,3);

  return 0;
}