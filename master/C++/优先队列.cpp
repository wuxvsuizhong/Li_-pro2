#include<queue>
#include<iostream>
#include<string>
using namespace std;



struct stu
{
	int age;
	string name;
};



struct stuless
{
	bool operator()(const stu& s1,const stu& s2)
	{		
		return s1.age < s2.age;
	}
};


int main()
{
	{
		priority_queue<int> mypri;
		mypri.push(10);
		mypri.push(11);
		mypri.push(102);
		mypri.push(13);
		mypri.push(14);
		mypri.push(15);//自动排序,大的值在前面

		while(!mypri.empty()){
			cout<<mypri.top()<<endl;
			mypri.pop();
		}
		cout<<"mypri.size():"<<mypri.size()<<endl;
	}

	{
		priority_queue<stu,vector<stu>,stuless> mypri;
		stu s1;
		s1.age = 20;
		s1.name = "first";
		stu s2;
		s2.age = 24;
		s2.name = "secnd";
		stu s3;
		s3.age = 25;
		s3.name = "third";
		mypri.push(s1);
		mypri.push(s2);
		mypri.push(s3);
		while(!mypri.empty()){
			cout<<mypri.top().age<<"\t"<<mypri.top().name<<endl;
			mypri.pop();
		}
	}

	return 0;
}
