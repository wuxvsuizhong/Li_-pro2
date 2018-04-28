#include<iostream>
#include<vector>




int main()
{
	std::vector<int> myvector(5);//如果分配了大小，那么默认值为0
	myvector.push_back(1);
	myvector.push_back(2);
	myvector.push_back(3);
	myvector.push_back(4);
	myvector.erase(myvector.begin()+3);
	myvector.push_back(5);
	myvector.pop_back();//弹出最后一个
	myvector.insert(myvector.begin()+1,999);
	
	myvector.push_heap(111);

	for(int i = 0;i<myvector.size();i++){
		//std::cout<<myvector[i]<<std::endl;
		std::cout<<myvector.at(i)<<std::endl;

	
	}


	return 0;
}
