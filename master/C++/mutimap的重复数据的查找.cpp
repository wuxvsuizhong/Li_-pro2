#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> myset;
    // multiset插入后自动排序,而且可以保存重复的值
    myset.insert(100);
    myset.insert(101);
    myset.insert(100);
    myset.insert(103);
    myset.insert(100);

    cout << "myset:";
    for (auto &v : myset) {
        cout << v << " ";
    }
    cout << endl;

    auto pfind = myset.find(100);
    cout << *pfind << endl;
    cout << "在myset中查找所有:" << *pfind << endl;
    auto allfind = myset.equal_range(100);
    // myset.equal_range(100)返回myset中100所在的元素范围(第一次,和最后一次的后一个位置)
    for (auto it = allfind.first; it != allfind.second; it++) {
        cout << *it << endl;
    }

    return 0;
}
