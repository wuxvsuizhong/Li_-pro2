#include <cstring>
#include <iostream>

#define FLAG 6

#if FLAG == 1
// 数组的初始化
int main() {
    using namespace std;
    int yams[3];
    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 6;

    int yamcosts[3] = {
        20, 30,
        5}; //{}可以用于cpp中初始化任意的类型，其中如果不包含数据那么就意味着会把数据初始化为0
    cout << "Total yams = ";
    cout << yams[0] + yams[1] + yams[2] << endl;
    cout << "the package with " << yams[1] << "yams cost ";
    cout << yamcosts[1] << "cents per yams\b";
    int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
    total = total + yams[2] * yamcosts[2];
    cout << "the total yam expense is " << total << " cenmts.\n";

    cout << "\bsize of yams array is " << sizeof yams;
    cout << " bytes\n";
    cout << "size of one element = " << sizeof yams[0];
    cout << " bytes.\n";
    return 0;
}
#endif

// 在数组中使用字符串
#if FLAG == 2
int main() {
    using namespace std;
    const int Size = 15;
    char name1[Size];
    char name2[Size] = "c++owboy";

    cout << "howdy,i'm " << name2;
    cout << "! what's your name?\n";
    cin >> name1;
    cout << "well! " << name1 << " your name has ";
    cout << strlen(name1)
         << " letters and is stored "; // strlen计算字符串长度不包含末尾\0
    cout << "in an array of " << sizeof(name1)
         << " bytes.\n"; // sizeof计算整个数组的长度
    cout << "Your initial is " << name1[0] << ".\n";
    name2[3] = '\0'; // 手动设置字符串数组的终止位置符号'\0'
    cout << "Here are the first 3 characters of my nane:";
    cout << name2 << endl;

    return 0;
}
#endif

#if FLAG == 3
// 字符串输入
int main() {
    using namespace std;
    const int ArSize = 20;
    char name
        [ArSize]; // 通常情况下，定义数组的时候是不能使用变量的，但是因为次数ArSize是一个const变量所以编译器会确定其大小，也就相当于把他可以看成常量
    char dessert[ArSize];

    cout << "enter your name :\n";
    cin >> name; // cin在遇到空白字符即终止接收输入，。空白字符如 空格 换行
                 // 制表符,也就是cin只能是每次读取一个单词
    cout << "enter your favorite dessert\n";
    cin >> dessert;
    cout << "i have some dilicous " << dessert;
    cout << " for yur," << name << endl;
    return 0;
}
#endif

#if FLAG == 4
// 每次读取一行cin.getline
int main() {
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "enter your name:\n";
    cin.getline(
        name,
        ArSize); // con.getline可以接受一整行，也就是遇到换行符才结束接受，如果输入时没有内容直接回车，则会用空字符来替换换行符
    cout << "enter your favorite dessert:\n";
    cin.getline(dessert, ArSize);
    cout << "I hace sone delicious " << dessert;
    cout << " for your " << name;

    return 0;
}
#endif

#if FLAG == 5
int main() {
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "输入你的名字：\n";
    cin.get(name, ArSize).get();  //这里要在尾部在加一个get()的原因是：cin.get()也可以一次读取一行。但是get不能丢弃换行符（getline可以丢弃）
    // 也就是说，在读取了一行输入完毕后，换行符还是保留在了输入中，下一次读取时如果还使用cin.get()/geline()会处理上一行的换行符，会误认为此次输入结束了
    // 座椅在末尾添加get()是为了吸收换行符的
    cout << "enter your favorite dessert:\n";
    cin.get(dessert, ArSize).get();
    cout << "I have sone delicious " << dessert;
    cout << " for you" << name << ".\n";

    return 0;
}
#endif

#if FLAG == 6
int main()
{
    using namespace std;
    cout<<"你的房子是哪一年修建的?\n";
    int year;
    // cin>>year; //cin也会把换行符留在输入中
    (cin>>year).get();  
    cout<<"街道地址是什么?\n";
    char address[80];
    cin.getline(address,80);    // 如果怕上一步的cin没有多一个get(),这里getline会直接遇到上一个cin遗留的换行符，用户无法获取输入
    cout<<"建造时间:"<<year<<endl;
    cout<<"地址:"<<address<<endl;
    cout<<"Done!\n";

    return 0;
}
#endif