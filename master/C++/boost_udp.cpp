#include<iostream>
#include<boost/asio.hpp>
#include<string>

using namespace std;

int main()
{
	boost::asio::io_service io_serviceA;
	boost::asio::ip::udp::socket udp_socket(io_serviceA);//用io_service给udp_socket初始化
	boost::asio::ip::udp::endpoint local_add(boost::asio::ip::address::from_string("127.0.0.1"),8000);//设置ip和端口
	udp_socket.open(local_add.protocol());//添加协议
	udp_socket.bind(local_add);//绑定ip和端口
	char receive_str[1024] = {0};//缓存区
	while(1)
	{
		boost::asio::ip::udp::endpoint sendpoint; 
		udp_socket.receive_from(boost::asio::buffer(receive_str,1024),sendpoint);
		cout<<"收到"<<receive_str<<endl;
		udp_socket.send_to(boost::asio::buffer(receive_str),sendpoint);
		memset(receive_str,0,sizeof(receive_str));


	}

	return 0;
}
