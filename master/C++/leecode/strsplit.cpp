#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string *s, char sep) {
    size_t prev_pos = 0, tmp_pos = 0;
    vector<string> res;
    tmp_pos = (*s).find(sep, prev_pos);
    while (tmp_pos != string::npos) {
        if (tmp_pos > prev_pos)
            // cout << (*s).substr(prev_pos, tmp_pos - prev_pos) << "|" << endl;
            res.push_back((*s).substr(prev_pos, tmp_pos - prev_pos));
        prev_pos = tmp_pos + sizeof(sep);
        tmp_pos = (*s).find(sep, prev_pos);
    };

    if (prev_pos < s->size()) {
        // cout << (*s).substr(prev_pos, s->size() - prev_pos) << "#" << endl;
        res.push_back((*s).substr(prev_pos, s->size() - prev_pos));
    }

    return res;
}
