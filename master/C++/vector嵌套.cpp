#include<iostream>
#include<vector>

int main()
{
	std::vector<int> myvector1;
	myvector1.push_back(1);
	myvector1.push_back(2);
	myvector1.push_back(3);

	std::vector<int> myvector2;
	myvector2.push_back(22);

	std::vector<int> myvector3;
	myvector3.push_back(33);
	myvector3.push_back(34);

	std::vector<std::vector<int>> allvector;
	allvector.push_back(myvector1);
	allvector.push_back(myvector2);
	allvector.push_back(myvector3);

	for(int i=0;i<allvector.size();i++)
	{
		for(int j=0;j<allvector[i].size();j++)
			std::cout<<allvector[i][j]<<"\t";

		std::cout<<std::endl;
	}	

	return 0;
}
