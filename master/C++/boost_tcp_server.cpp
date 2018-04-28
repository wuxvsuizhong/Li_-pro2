#include<iostream>
#include<boost/asio.hpp>

using namespace std;


int main()
{
	boost::asio::io_service ioser;	
	boost::asio::ip::tcp::acceptor myacceptor(ioser,boost::asio::ip::tcp::endpoint(ip::tcp::v4(),1100));//自动获取本机IP,然后设置端口
	while(1)
	{
		boost::asio::ip::tcp::socket mysock(ioser);
		myacceptor.accept(mysock);
		cout<<"客户端"<<mysock.remote_endpoint().address()<<mysock.remote_endpoint().port()<<"链接上"<<endl;
	}



	return 0;
}

