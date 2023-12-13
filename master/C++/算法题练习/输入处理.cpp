#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "strsplit.h"

// vector<string> split(string *s, char sep) {
//     size_t prev_pos = 0, tmp_pos = 0;
//     vector<string> res;
//     tmp_pos = (*s).find(sep, prev_pos);
//     while (tmp_pos != string::npos) {
//         if (tmp_pos > prev_pos)
//             // cout << (*s).substr(prev_pos, tmp_pos - prev_pos) << "|" <<
//             endl; res.push_back((*s).substr(prev_pos, tmp_pos - prev_pos));
//         prev_pos = tmp_pos + sizeof(sep);
//         tmp_pos = (*s).find(sep, prev_pos);
//     };

//     if (prev_pos < s->size()) {
//         // cout << (*s).substr(prev_pos, s->size() - prev_pos) << "#" <<
//         endl; res.push_back((*s).substr(prev_pos, s->size() - prev_pos));
//     }

//     return res;
// }

template <typename T> void extendVec(vector<T> &src, vector<T> &itms);

int main() {
    vector<string> str_list;
    string s;
    while (getline(cin, s)) {
        if (s.empty())
            break;
        str_list.push_back(s);
    }

    // vector<string>::iterator it = str_list.begin();
    // for (it = str_list.begin(); it != str_list.end(); it++) {
    //     cout << *it << " ";
    // }
    // cout << endl;
    // cout << "len(str_list)=" << str_list.size() << endl;

    for_each(str_list.begin(), str_list.end(),
             [](string val) { cout << val << endl; });

    vector<string> all_str;

    for (vector<string>::iterator it = str_list.begin(); it != str_list.end();
         it++) {
        vector<string> ret = split(&(*it), ' ');
        // for_each(ret.begin(), ret.end(),
        //          [](string val) { cout << val << endl; });
        // extend(&all_str, &ret);
        // all_str.insert(all_str.end(), ret.begin(), ret.end());
        extendVec(all_str, ret);
    }

    for_each(all_str.begin(), all_str.end(),
             [](string val) { cout << val << " "; });
    cout << endl;

    char c = 'A';
    cout << char(c + 1) << endl;
}

template <typename T> void extendVec(vector<T> &src, vector<T> &itms) {
    src.insert(src.end(), itms.begin(), itms.end());
}