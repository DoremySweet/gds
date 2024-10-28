#include <iostream>
#include<filesystem>
#include<type_traits>
#include"../net/net.h"


int main(int argc, char* args[])
{
	try
	{
		"0:123456:12345:1234::0""::33:222:111:0""1::""9:9""::::"":"":::""1";
		std::cout << net::ip_type("::");
		
	}
	catch (const std::exception&) {}

	return 0;
}
