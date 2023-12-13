#include <iostream>
#include <string>

#define Chapter 2

#if Chapter == 1
int main() {
    using namespace std;
    char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "panter";

    cout << "enter a kind of feline:";
    cin >> charr1;
    cout << "enter another kinf of feline:";
    cin >> str1; //string会自动根据获取的输入确定长度值
    cout << "here are some felines:\n";
    cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;
    cout << "the third letter in " << charr2 << " is " << charr2[2] << endl;
    cout << "the third letter in " << str2 << " is " << str2[2] << endl;

    return 0;
}

#endif

#if Chapter == 2
int main()
{
  using namespace std;
  string s1 = "penggu";
  string s2,s3;

  cout<<"可以把一个str赋值给另外一个str: s2 = s1\n";
  s2 = s1;
  cout<<"可以赋值ctring风格的字符串给string\n";
  cout<<"s2 = \"buzzard\"\n";
  s2 = "buzzard";
  cout<<"s2: "<<s2<<endl;
  cout<<"可以组合字符串:s3 = s1+s2\n";
  s3 = s1 + s2;
  cout<<" s3: "<<s3<<endl;
  cout<<"可以追加字符串\b";
  s1+=s3;
  cout<<"s1的内容:"<<s1<<endl;
  s2+="for a day";
  cout<<"s2 += \"for a day\" yield s2 = "<<s2<<endl;

  return 0;
}

#endif

