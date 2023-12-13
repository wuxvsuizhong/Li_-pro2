#include "strsplit.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Sulution {
  public:
    int openlock(vector<string> &deadends, string target) {
        if (target == "0000") {
            return 0;
        }

        // 把deadends里的所有元素初始化到无序集合dead中
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) {
            return -1;
        }
        // for_each(dead.begin(), dead.end(), [](string v) { cout << v << " ";
        // });

        auto num_prev = [](char x) -> char { return x == '0' ? '9' : x - 1; };
        auto num_succ = [](char x) -> char { return x == '9' ? '0' : x + 1; };

        auto get = [&](string &status) -> vector<string> {
            vector<string> ret;
            for (int i = 0; i < 4; i++) {
                cout << "next状态:" << status << endl;
                char num = status[i];
                status[i] = num_prev(num);
                ret.push_back(status);
                status[i] = num_succ(num);
                ret.push_back(status);
                status[i] = num;
            }
            return ret;
        };

        queue<pair<string, int>> q;
        q.emplace("0000", 0);
        unordered_set<string> seen = {"0000"};

        while (!q.empty()) {
            auto [status, step] = q.front();
            q.pop();
            for (auto &&next_status : get(status)) {
                if (!seen.count(next_status) && !dead.count(next_status)) {
                    if (next_status == target) {
                        return step + 1;
                    }
                    q.emplace(next_status, step + 1);
                    seen.insert(move(next_status));
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<string> deadends;
    string target;
    string t_s;
    getline(cin, t_s);
    vector<string> ret = split(&t_s, ' ');
    deadends.insert(deadends.end(), ret.begin(), ret.end());
    cin >> target;

    for_each(deadends.begin(), deadends.end(),
             [](string val) { cout << val << endl; });

    Sulution s;
    int res = s.openlock(deadends, target);
    cout << "res=" << res << endl;
}