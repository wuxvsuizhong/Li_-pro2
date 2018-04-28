#include<thread>
#include<iostream>

using namespace std;
using namespace std::this_thread;



int main()
{
	auto n=thread::hardware_concurrency();
	cout<<n<<endl;
	cout<<"thread="<<get_id()<<endl;
	return 0;

}
