// unique_ptr可以转换为shared_ptr
// 但是反向不可以转换，shared_ptr不可以转换为unique_ptr
// 手动类型转换时使用移动语义move

#include <iostream>
#include <memory>
using std::cout, std::endl, std::shared_ptr, std::make_shared, std::unique_ptr,
    std::make_unique;

unique_ptr<int> get_uniq() {
  unique_ptr<int> ua = make_unique<int>(10);
  return ua;
}

int main(int argc, char const *argv[]) {
  unique_ptr<int> p1 = make_unique<int>(100);
  shared_ptr<int> p2 = std::move(p1);
  cout << "p2.use_count:" << p2.use_count() << endl;

  // shared_ptr<int>p4 = p1; 无法直接转换，需要使用移动语义切换指针所有权

  shared_ptr<int> p3 = get_uniq();
  cout << "p2.use_count:" << p3.use_count() << endl;
  // 类型转换不会增加引用计数

  return 0;
}
