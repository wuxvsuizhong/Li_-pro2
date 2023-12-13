/*
输入int型数组，询问该数组能否分成两组，使得两组中各元素加起来的和相等，并且，所有5的倍数必须在其中一个组中，所有3的倍数在另一个组中（不包括5的倍数），不是5的倍数也不是3的倍数能放在任意一组，可以将数组分为空数组，能满足以上条件，输出true；不满足时输出false。

数据范围：每个数组大小满足1≤n≤50  ，输入的数据大小满足∣val∣≤500 输入描述：
第一行是数据个数，第二行是输入的数据

输出描述：
返回true或者false

示例1
输入：
4
1 5 -5 1

输出：
true

说明：
第一组：5 -5 1
第二组：1
示例2
输入：
3
3 5 8

输出：
false
说明：
由于3和5不能放在同一组，所以不存在一种分法。
*/

#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int quantity = 0;
    cin >> quantity;

    vector<int> threen, fiven, others;
    int tmp_n = 0;

    for (int i = 0; i < quantity; i++) {
        cin >> tmp_n;
        if (tmp_n % 5 == 0)
            fiven.push_back(tmp_n);
        else if (tmp_n % 3 == 0) {
            threen.push_back(tmp_n);
        } else {
            others.push_back(tmp_n);
        }
    }

    auto sum = [&](vector<int> vals) {
        int sum = 0;
        for (auto &v : vals)
            sum += v;
        return sum;
    };

    function<bool(vector<int> & grp)> grpCalc;
    vector<bool> book;
    for (int i = 0; i < others.size(); i++) {
        book.push_back(false);
    }

    int oths = sum(others), threes = sum(threen), fives = sum(fiven);
    grpCalc = [&](vector<int> &grp) -> bool {
        int sumgrp = sum(grp);
        if (threes + sumgrp == fives + (oths - sumgrp) ||
            fives + sumgrp == threes + (oths - sumgrp))
            return true;
        else {
            if (grp.size() == others.size())
                return false;
            else {
                for (int i = 0; i < others.size(); i++) {
                    if (!book[i]) {
                        book[i] = true;
                        grp.push_back(others[i]);
                        if (grpCalc(grp) || grpCalc(grp))
                            return true;
                        grp.pop_back();
                        book[i] = false;
                    }
                }
                return false;
            }
        }
    };

    vector<int> tmp_grp;
    bool ret = grpCalc(tmp_grp);
    if (ret)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}