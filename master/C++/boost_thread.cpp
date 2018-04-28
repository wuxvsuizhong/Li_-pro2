#include<iostream>
#include<boost/thread.hpp>

using namespace std;
using namespace boost;



void wait(int seconds)
{
	boost::this_thread::sleep(boost::posix_time::seconds(seconds));
}

void th1()
{
	try{
		for(int i=0;i<5;i++)
		{
			wait(1);
			cout<<i<<endl;
		}
	}
	catch(boost::thread_interrupted&)
	{
		cout<<"interrupt"<<endl;
	}
}

int main()
{
	boost::thread t(th1);
	wait(3);
	t.interrupt();//打断正在执行的线程
	t.join();
	cout<<"main thread"<<endl;
}

