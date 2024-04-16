#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  map<int, vector<vector<int>>> mData;

  mData[0] = {{1, 1, 0, 1}, {0, 0, 1, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}};

  int arr[4][4] = {
    {1,2,3,4},
    {0,1,0,1},
    {1,0,1,0},
    {1,1,1,1}
  };

  cout<<sizeof(arr)/sizeof(arr[0])<<endl;




  return 0;
}
