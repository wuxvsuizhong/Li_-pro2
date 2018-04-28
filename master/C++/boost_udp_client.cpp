#include<boost/asio.hpp>
#include<iostream>


using namespace std;

int main()
{
	boost::asio::io_service io_serviceA;
	boost::asio::ip::udp::socket udp_socket(io_serviceA);
	boost::asio::ip::udp::endpoint local_add(boost::asio::ip::address::from_string("127.0.0.1"),8000);
	udp_socket.open(local_add.protocol());
	char receive_str[1024] = {0};
	char sendstr[100] = {0};
	while(1)
	{
		cout<<"请输入：";
		while(cin.get(sendstr,sizeof(sendstr))){
			udp_socket.send_to(boost::asio::buffer(sendstr,strlen(sendstr)),local_add);
			udp_socket.receive_from(boost::asio::buffer(receive_str,1024),local_add);
			cout<<"收到"<<receive_str<<endl;
		}
	}
	return 0;
}
