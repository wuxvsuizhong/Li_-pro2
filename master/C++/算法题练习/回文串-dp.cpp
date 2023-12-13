/*
对于长度为n的一个字符串A（仅包含数字，大小写英文字母），请设计一个高效算法，计算其中最长回文子串的长度。
数据范围:10001≤n≤1000
要求：空间复杂度 O(1)O(1)，时间复杂度 O(n^2)O(n^2)
进阶:  空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)
示例1
输入：
"ababc"
返回值：
3
说明：
最长的回文子串为"aba"与"bab"，长度都为3

示例2
输入：
"abbba"
返回值：
5

示例3
输入：
"b"
返回值：
1
*/
#include <iostream>
#include <unordered_set>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::unordered_set;
using std::vector;

unsigned int dp(string &s, unordered_set<string> &ret) {
    // 动态规划法
    unsigned int len = s.size();
    bool dp[len][len];
    unsigned int maxlen = 0;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                if (j - i <= 2) // 如果j->i的间距小于2，而且j,i位置的元素相等
                    dp[j][i] = true; // 那么说明从j->i之间的字符串切片子串是回文
                else {
                    // 这里其实就是来自动态规划的状态转移方程
                    dp[j][i] ==
                        dp[j + 1][i - 1]; // 否则当前从j->i 是否回文取决于从j-1
                                          // -> i+1 之间的切片字符子串是否为回文
                }
            } else {
                dp[j][i] = false;
            }

            string sub_str = s.substr(j, i - j + 1);
            if (dp[j][i] && !sub_str.empty()) {
                // ret.push_back(sub_str);
                ret.emplace(sub_str);
                maxlen = i - j + 1 > maxlen ? i - j + 1 : maxlen;
            }
        }
    }

    return maxlen;
}

unsigned int extend(string &s, unordered_set<string> &ret) {
    unsigned int maxlen = 0;
    // 双指针法+中心扩散法；所谓的中心扩散法是只每次选相邻或者是三个相邻的元素，逐步向两边扩散
    for (int i = 0; i < s.size(); i++) {
        int l = i, r = l + 1; // 左右双指针选相邻的两个位置元素
        while (l >= 0 && l < s.size() && r < s.size() && r >= 0) {
            if (s[l] == s[r]) {
                maxlen = r - l + 1 > maxlen ? r - l + 1 : maxlen;
                // cout<<s.substr(l,r-l+1);
                // ret.push_back(s.substr(l, r - l + 1));
                ret.emplace(s.substr(l, r - l + 1));
                l -= 1;
                r += 1;
            } else
                break;
        }
    }

    for (int i = 1; i < s.size(); i++) {
        int l = i - 1,
            r = i +
                1; // 左右双指针选i位置左右相邻的两个元素，l-r之间的位置至少距离是3个字符
        while (l >= 0 && l < s.size() && r >= 0 && r < s.size()) {
            if (s[l] == s[r]) {
                maxlen = r - l + 1 > maxlen ? r - l + 1 : maxlen;
                // cout<<s.substr(l,r-l+1);
                // ret.push_back(s.substr(l, r - l + 1));
                ret.emplace(s.substr(l, r - l + 1));
                l -= 1;
                r += 1;
            } else
                break;
        }
    }

    return maxlen;
}

int main() {
    string s;
    // std::vector<string> ret;
    unordered_set<string> ret;
    std::getline(cin, s);
    int maxlen = 0;

    // maxlen = extend(s,ret);    //中心扩展法
    maxlen = dp(s, ret); // 动态规划dp法

    cout << "字符串中筛选出的回文字符串有:";
    for (unordered_set<string>::iterator s = ret.begin(); s != ret.end(); s++) {
        cout << *s << " ";
    }
    cout << "\n"
         << "最长的回文字符串长度为:" << maxlen << "\n";

    return 0;
}