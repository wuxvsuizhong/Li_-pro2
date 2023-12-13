/*
给出两个字符串 s 和 t，要求在 s 中找出最短的包含 t 中所有字符的连续子串。

数据范围：0≤∣S∣,∣T∣≤10000，保证s和t字符串中仅包含大小写英文字母
要求：进阶：空间复杂度 O(n)O(n) ， 时间复杂度 O(n)O(n)
例如：
S ="XDOYEZODEYXNZ"
T ="XYZ"
找出的最短子串为"YXNZ""YXNZ".

注意：
如果 s 中没有包含 t 中所有字符的子串，返回空字符串 “”；
满足条件的子串可能有很多，但是题目保证满足条件的最短的子串唯一。

示例1
输入：
"XDOYEZODEYXNZ","XYZ"
返回值：
"YXNZ"
示例2
输入：
"abcAbA","AA"
返回值：
"AbA"
*/

/*这个问题有三种解法，1.重复元素替换法 2.深度搜索dfs凑组合法,4.滑动窗口*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::count;
using std::cout;
using std::map;
using std::string;
using std::vector;

void dfs(string &s, string &patt) { // 深度搜素法
    map<char, vector<int>> opmap = {};
    for (int i = 0; i < s.size(); i++) {
        if (patt.find(s[i]) !=
            string::npos) { // 再待匹配的字符串中匹配到了patt中的某个字符
            if (opmap.find(s[i]) != opmap.end())
                opmap[s[i]].push_back(i);
            else
                opmap[s[i]] = vector<int>{i};
        }
    }

    map<char, vector<int>> rec = opmap;
    for (auto &item : opmap) {
        cout << "[";
        for (auto &k : item.second)
            cout << k << " ";
        cout << "]\n";
    }

    vector<vector<int>> res = {};
    std::function<void(vector<int> &)> inner_dfs;
    inner_dfs = [&](vector<int> &grp) { // 这种深度递归得到的是全排列
        if (grp.size() == patt.size()) {
            res.push_back(grp);
            return;
        }

        for (auto &item : opmap) {
            const char &key = item.first;
            if (count(item.second.begin(), item.second.end(), -1))
                continue;
            for (size_t i = 0; i < opmap[key].size(); i++) {
                auto val_bak = opmap[key][i];
                opmap[key][i] = -1;
                grp.push_back(rec[key][i]);
                inner_dfs(grp);
                grp.pop_back();
                opmap[key][i] = val_bak;
                // }
            }
        }
    };

    // 筛选出最短的字符串
    vector<int> grp = {};
    inner_dfs(grp);
    int minpos = 0, minlen = s.size();
    for (auto &item : res) {
        int begin = *std::min_element(item.begin(), item.end());
        int slice_len = *std::max_element(item.begin(), item.end()) - begin + 1;
        if (slice_len < minlen) {
            minlen = slice_len, minpos = begin;
        }
        for (int &n : item)
            cout << n << " ";
        cout << "\n";
    }
    cout << s.substr(minpos, minlen) << "\n";
}

void getSubstrByReplace(const string &s, const string &patt) { // 逐个替换法
    vector<vector<int>> rec = {};

    int strat_flag = -1;
    string patt_cp = patt;

    for (int i = 0; i < s.size(); i++) {

        size_t pos = patt_cp.find(s[i]);
        if (pos != string::npos) {
            if (strat_flag == -1)
                strat_flag = i;
            patt_cp.replace(pos, 1, "");
        }
        if (patt_cp.empty()) {
            patt_cp = patt;
            rec.push_back(vector<int>{strat_flag, i + 1});
            i = strat_flag;
            strat_flag = -1;
            continue;
        }
    }

    for (auto &item : rec) {
        for (auto &n : item) {
            cout << n << " ";
        }
        cout << "\n";
        cout << s.substr(item[0], item[1] - item[0] + 1) << " \n";
    }
}

void GetSubstrBySlideWin(const string &s,
                         const string &patt) { // 通过滑动窗口实现
    int start = -1, end = -1, cnt = 0, i = 0;
    vector<vector<int>> rec = {};
    while (i < s.size()) {
        if (patt.find(s[i]) != string::npos) { // s和patt中有相同的字符
            if (start == -1) {
                start = i;
                end = start;
                cnt += 1;
            } else {
                cout << s.find_first_of(start, s[i]) << "\n";
                end = i;
                cnt += 1;
            }
            if (cnt == patt.size()) {
                rec.push_back(vector<int>{start, end});
                i = start;
                start = -1;
                end = start;
                cnt = 0;
            }
        }
        i++;
    }

    for (auto &item : rec) {
        for (auto &n : item) {
            cout << n << " ";
        }
        cout << "\n";
        cout << s.substr(item[0], item[1] - item[0] + 1) << " \n";
    }
}

int main() {
    string s, patt;
    cin >> s >> patt;

    // dfs(s, patt);
    // getSubstrByReplace(s, patt);
    GetSubstrBySlideWin(s, patt);
    return 0;
}