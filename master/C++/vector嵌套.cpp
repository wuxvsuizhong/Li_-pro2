#include <iostream>
#include <vector>

int main() {
  std::vector<int> myvector1;
  myvector1.push_back(1);
  myvector1.push_back(2);
  myvector1.push_back(3);

  std::vector<int> myvector2;
  myvector2.push_back(22);

  std::vector<int> myvector3;
  myvector3.push_back(33);
  myvector3.push_back(34);

  std::vector<std::vector<int>> allvector;
  allvector.push_back(myvector1);
  allvector.push_back(myvector2);
  allvector.push_back(myvector3);

  for (int i = 0; i < allvector.size(); i++) {
    for (int j = 0; j < allvector[i].size(); j++)
      std::cout << allvector[i][j] << "\t";

    std::cout << std::endl;
  }

  // 嵌套vectro的初始化
  std::vector<std::vector<int>> data = {
      {1, 2, 3, 4},
      {11, 22, 33, 44},
      {4, 3, 2, 1},
  };
  std::cout << "=====================\n";
  for (auto &arr : data) {
    for (auto &i : arr) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "end\n";

  return 0;
}
