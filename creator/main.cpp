#include <iostream>
#include<filesystem>
#include<type_traits>
#include"net.h"


int main(int argc, char* args[])
{
	try
	{
		"0:123456:12345:1234::0""::33:222:111:0""1::""9:9""::::"":"":::""1";
		std::cout << net::ip_type("::");
		
		/*
		std::string str;
		for (int i = 1; i < 2; i++) {
			for (int j = 1; j < 2; j++) {
				for (int k = 0; k < 256; k++) {
					for (int l = 0; l < 256; l++) {
						str = std::to_string(i) + '.' + std::to_string(j) + '.' + std::to_string(k) + '.' + std::to_string(l);
						if (net::ip_type(str) != net::IP::TYPE::ipv4_type) std::cout << "error:" << str << std::endl;
					}
				}
			}
		}*/
//		net::IP::TYPE ret_type = net::ip_type("255.255.255.255");
//		std::cout << std::endl << ret_type << std::endl;
		/*
		std::string str = "string";
		std::cin.tie(nullptr);
		char arg[] = R"(D:\pacs\ImagesNet)";
		const std::string_view path_arg(arg);
		pacs_translate::local_slave slv(path_arg);
		slv.traverse();
		pacs_translate::exam_list list(slv);*/
	}
	catch (const std::exception&) {}

	return 0;
}
