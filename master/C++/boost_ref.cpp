#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/ref.hpp>
#include <functional>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
// using namespace boost;

void print(std::ostream &os, int n) { os << n << endl; }

int main() {
    /*不能拷贝的对象用ref*/
    boost::function<void(int)> pt = boost::bind(print, boost::ref(cout), _1);
    vector<int> myv = {1, 2, 3, 4, 5};

    for_each(myv.begin(), myv.end(), pt);
    return 0;
}
