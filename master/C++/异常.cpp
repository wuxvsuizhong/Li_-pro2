#include <iostream>
#include <string.h>

using namespace std;

class wrong // 自定义异常
{};

int intdiv(int a, int b) {
  try /* try...catch...捕获异常 */
  {
    if (b == 0) {
      throw wrong();
      // throw 10;
    }
    int c = a / b;
    return c;
  }
  // catch(int data)
  catch (wrong data) {
    cout << "除法异常" << endl;
    return -1;
  }
}

int divA(int a, int b) { return a / b; }

int main() {
  int x, y;
  cin >> x >> y;
  try { /* try 语句块抛出可能的异常 */
    if (y == 0) {
      throw "被除数为0";
    } else if (x == 0) {
      throw "除数为0";
    }
  } catch (const char *s) { /* catch 语句块捕获异常 */
    if (strcmp(s, "被除数为0") == 0) {
      cout << "被除数为0,请重新输入";
      cin >> x >> y;
    } else if (s, "除数为0") {
      cout << "除数为0,请重新输入";
      cin >> x >> y;
    }
  }

  cout << intdiv(x, y);

  return 0;
}
