#pragma once
#include<iostream>
#include<string>
#include<stdexcept>
#include<array>
#include"parse/token.h"

namespace net {

	class IP {
	public:
		enum TYPE {
			error_type = 0,
			ipv4_type,
			ipv6_type
		};

		explicit IP(const std::string_view& addr);
		void set_ip(const std::string_view& addr);
		void print() const;

	private:
		std::string _addr;
		TYPE _type;
	};

	IP::IP(const std::string_view& addr) :_addr(addr), _type(error_type) {



	}

	void IP::set_ip(const std::string_view& addr) {

	}

	void IP::print() const { std::cout << "type" << _type << " address:" << _addr; }

	class PORT {
	public:
		explicit PORT(const int port);
		void set_port(const int port);
		void print() const;

	private:
		int _port;
	};

	PORT::PORT(int port) : _port(port) {}

	void PORT::set_port(int port) {
		this->_port = port;
	}

	void PORT::print() const {
		std::cout << "port:" << _port;
	}

	class TCP {
	public:
		explicit TCP(const std::string_view& addr, const int port);
		void print() const;

	private:
		IP _ip;
		PORT _port;
	};

	TCP::TCP(const std::string_view& addr, const int port) :_ip(addr), _port(port) {}

	void TCP::print() const { std::cout << "TCP:["; _ip.print(); std::cout << " "; _port.print(); std::cout << "]"; }

	class UDP {
	public:
		explicit UDP(const std::string_view& addr, const int port);
		void print() const;

	private:
		IP _ip;
		PORT _port;
	};

	UDP::UDP(const std::string_view& addr, const int port) :_ip(addr), _port(port) {}

	void UDP::print() const { std::cout << "UDP:["; _ip.print(); std::cout << " "; _port.print(); std::cout << "]"; }

	enum IPV6_TOKEN_TYPE {
		ERROR_TYPE = 0,
		DIGIT_TYPE,
		COLON_TYPE,
		DOUBLE_COLON_TYPE,
		END_TYPE
	};

	enum IPV6_PARSE_ERROR_TYPE {
		UNKNOW =0
	};

	using TOKEN_STREAM = std::vector<std::pair<int, int>>;

	class IPV6_AST{
	public:
		virtual bool is_error() { return false; }
		virtual void print_ast() { std::cout << "IPV6_AST:" << std::endl; }
	};

	class IPV6_AST_EMPTY :public IPV6_AST {
	public:
		virtual bool is_error() { return false; }
		virtual void print_ast() { std::cout << "IPV6_AST_EMPTY:" << std::endl; }
	};

	class IPV6_AST_NULL :public IPV6_AST {
	public:
		virtual bool is_error() { return false; }
		virtual void print_ast() { std::cout << "IPV6_AST_NULL:" << std::endl; }
	};
	
	class IPV6_AST_ERROR :public IPV6_AST {
	public:
		IPV6_AST_ERROR(int type,std::string str, IPV6_AST *ast):_type(type),_str(str),_ast(ast){}
		virtual bool is_error() { return true; }
		virtual void print_ast() {
			std::cout << "IPV6_AST_ERROR:type"<<_type<<std::endl<<_str << std::endl; 
			_ast->print_ast();
		}
		

	private:
		IPV6_AST* _ast;
		int _type;
		std::string _str;
	};
/*
	class IPV6_AST_TERMINATE :public IPV6_AST {
	public:
		IPV6_AST_TERMINATE(std::pair<int, int> terminate): _terminate(terminate){}
		virtual bool is_error() { return false; }
		virtual void print_ast() { std::cout << "IPV6_AST_TERMINATE:<"<<_terminate.first<<_terminate.second <<">" << std::endl; }

	private:
		std::pair<int, int> _terminate;
	};*/

	class IPV6_AST_NUMBER: public IPV6_AST {
	public:
		IPV6_AST_NUMBER(int value, IPV6_AST* ast) :_value(value),_ast(ast) {}
		virtual bool is_error() { return false; }
		virtual void print_ast() {
			std::cout <<"IPV6_AST_NUMBER:" << _value;
			std::cout << std::endl;
			_ast->print_ast();
			std::cout << std::endl;
		};
	private:
		int _value;
		IPV6_AST* _ast;
	};

	class IPV6_AST__NUMBER :public IPV6_AST {
	public:
		IPV6_AST__NUMBER(int value, IPV6_AST* ast) :_value(value),_ast(ast) {}
		virtual bool is_error() { return false; }
		virtual void print_ast() {
			std::cout <<"IPV6_AST__NUMBER:" << _value;
			std::cout << std::endl;
			_ast->print_ast();
			std::cout << std::endl;
		};
	private:
		int _value;
		IPV6_AST* _ast;

	};

	class IPV6_AST_DOUBLE_COLON :public IPV6_AST {
	public:
		virtual bool is_error() { return false; }
		virtual void print_ast() { std::cout << "DOUBLE_COLON:" << std::endl; }
	};

	class IPV6_AST_LINK :public IPV6_AST {
	public:
		IPV6_AST_LINK(IPV6_AST* ast_0, IPV6_AST* ast_1, IPV6_AST* ast_2) :_ast_0(ast_0), _ast_1(ast_1), _ast_2(ast_2) {}
		virtual bool is_error() { return false; }
		virtual void print_ast() {
			std::cout << "IPV6_AST_LINK:" ;
			_ast_0->print_ast();
			_ast_1->print_ast();
			_ast_2->print_ast();
			std::cout << std::endl;
		}
	private:
		IPV6_AST* _ast_0;
		IPV6_AST* _ast_1;
		IPV6_AST* _ast_2;

	};

	class IPV6_AST__LINK :public IPV6_AST {
	public:
		IPV6_AST__LINK(IPV6_AST* ast_0, IPV6_AST* ast_1, IPV6_AST* ast_2) :_ast_0(ast_0), _ast_1(ast_1), _ast_2(ast_2) {}
		virtual bool is_error() { return false; }
		virtual void print_ast() {
			std::cout << "IPV6_AST__LINK:";
			_ast_0->print_ast();
			_ast_1->print_ast();
			_ast_2->print_ast();
			std::cout << std::endl;
		}
	private:
		IPV6_AST* _ast_0;
		IPV6_AST* _ast_1;
		IPV6_AST* _ast_2;
	};

	class IPV6_AST___LINK :public IPV6_AST {
	public:
		IPV6_AST___LINK(IPV6_AST* ast_0) :_ast_0(ast_0) {}
		virtual bool is_error() { return false; }
		virtual void print_ast() {
			std::cout << "IPV6_AST___LINK:";
			_ast_0->print_ast();
			std::cout << std::endl;
		}
	private:
		IPV6_AST* _ast_0;
	};

	class IPV6_AST_IP :public IPV6_AST {
	public:
		IPV6_AST_IP() = delete;
		IPV6_AST_IP(IPV6_AST* ast):_ast(ast){}
		virtual bool is_error() { return false; }
		virtual void print_ast() {
			std::cout << "IPV6:"<< std::endl;
			_ast->print_ast();
			std::cout << std::endl;
		}
	private:
		IPV6_AST* _ast;
	};

	IPV6_AST* parse_ipv6__number(TOKEN_STREAM& token, size_t& pointer) {
		std::cout << "parse_ipv6__number" << std::endl;
		if (token[pointer].first == IPV6_TOKEN_TYPE::DIGIT_TYPE) {
			pointer++;
			IPV6_AST* ast__number = parse_ipv6__number(token, pointer);
			if (ast__number->is_error()) return new IPV6_AST_ERROR(0, "cant match <_number>", ast__number);
			return new IPV6_AST__NUMBER(token[pointer - 1].second, ast__number);
		}
		else return new IPV6_AST__NUMBER(-1, new IPV6_AST_EMPTY());
	}

	IPV6_AST* parse_ipv6_number(TOKEN_STREAM& token, size_t& pointer) {
		std::cout << "parse_ipv6_number" << std::endl;
		if (token[pointer].first == IPV6_TOKEN_TYPE::DIGIT_TYPE) {
			pointer++;
			IPV6_AST* ast__number = parse_ipv6__number(token, pointer);
			if(ast__number->is_error()) return new IPV6_AST_ERROR(0, "cant match <_number>", ast__number);
			return new IPV6_AST_NUMBER(token[pointer - 1].second, ast__number);
		}
		else return new IPV6_AST_ERROR(0, "unexcept token type", new IPV6_AST_NULL());
	}

	IPV6_AST* parse_ipv6__link(TOKEN_STREAM& token, size_t& pointer) {
		std::cout << "parse_ipv6__link" << std::endl;
		if (token[pointer].first == IPV6_TOKEN_TYPE::DIGIT_TYPE) {
			IPV6_AST* ast_number = parse_ipv6_number(token, pointer);
			if (ast_number->is_error()) return new IPV6_AST_ERROR(0, "cant match <number>", ast_number);
			else if (token[pointer].first == IPV6_TOKEN_TYPE::COLON_TYPE) {
				// number [colon] _link
				pointer++;
				IPV6_AST* ast__link = parse_ipv6__link(token, pointer);
				if (ast__link->is_error()) return new IPV6_AST_ERROR(0, "cant match <_link>", ast__link);
				return new IPV6_AST__LINK(ast_number, ast__link, new IPV6_AST_NULL());
			}
			else if (token[pointer].first == IPV6_TOKEN_TYPE::END_TYPE|| token[pointer].first == IPV6_TOKEN_TYPE::DOUBLE_COLON_TYPE) {
				return new IPV6_AST__LINK(ast_number, new IPV6_AST_NULL(), new IPV6_AST_NULL());
			}
			else return  new IPV6_AST_ERROR(0, "cant match <_link>", ast_number);
		}
		else return new IPV6_AST_ERROR(0, "cant match <_link>", new IPV6_AST_NULL());
	}

	IPV6_AST* parse_ipv6___link(TOKEN_STREAM& token, size_t& pointer) {
		std::cout << "parse_ipv6___link" << std::endl;
		if (token[pointer].first == IPV6_TOKEN_TYPE::DIGIT_TYPE) {
			IPV6_AST* ast__link = parse_ipv6__link(token, pointer);
			if (ast__link->is_error()) return new IPV6_AST_ERROR(0, "cant match <_link>", ast__link);
			return new IPV6_AST__LINK(ast__link, new IPV6_AST_NULL(), new IPV6_AST_NULL());
		}
		else if (token[pointer].first == IPV6_TOKEN_TYPE::END_TYPE) {
			return new IPV6_AST___LINK(new IPV6_AST_EMPTY());
		}
		else return new IPV6_AST_ERROR(0, "cant match <__link>", new IPV6_AST_NULL());
	}

	IPV6_AST* parse_ipv6_link(TOKEN_STREAM& token, size_t& pointer) {
		std::cout << "parse_ipv6_link" << std::endl;

			if (token[pointer].first == IPV6_TOKEN_TYPE::DOUBLE_COLON_TYPE) {
				pointer++;
				if (token[pointer].first == IPV6_TOKEN_TYPE::END_TYPE) {
					//[double colon] [end]
					return new IPV6_AST_LINK(new IPV6_AST_DOUBLE_COLON(),new IPV6_AST_NULL(), new IPV6_AST_NULL());
				}
				else if (token[pointer].first == IPV6_TOKEN_TYPE::DIGIT_TYPE) {
					//[double colon] _link
					IPV6_AST* ast__link = parse_ipv6__link(token, pointer);
					if (ast__link->is_error()) return new IPV6_AST_ERROR(0, "cant match <_link>", ast__link);
					return new IPV6_AST_LINK(new IPV6_AST_DOUBLE_COLON(), ast__link, new IPV6_AST_NULL());
				}
				else return new IPV6_AST_ERROR(0, "unexcept token type", new IPV6_AST_NULL());
			}
			else if (token[pointer].first == IPV6_TOKEN_TYPE::DIGIT_TYPE) {
				IPV6_AST* ast__link = parse_ipv6__link(token, pointer);
				if (ast__link->is_error()) return new IPV6_AST_ERROR(0, "cant match <_link>", ast__link);
				if (token[pointer].first == IPV6_TOKEN_TYPE::END_TYPE) {
					//_link [end]
					return new IPV6_AST_LINK(ast__link, new IPV6_AST_NULL(), new IPV6_AST_NULL());
				}
				else if (token[pointer].first == IPV6_TOKEN_TYPE::DOUBLE_COLON_TYPE) {
					pointer++;
					if (token[pointer].first == IPV6_TOKEN_TYPE::DIGIT_TYPE|| token[pointer].first == IPV6_TOKEN_TYPE::END_TYPE) {
						//_link [double colon] __link
						IPV6_AST* ast___link = parse_ipv6___link(token, pointer);
						if (ast___link->is_error()) return new IPV6_AST_ERROR(0, "cant match <__link>", ast___link);
						return new IPV6_AST_LINK(ast__link,new IPV6_AST_DOUBLE_COLON(), ast___link);
					}
					else return new IPV6_AST_ERROR(0, "cant match <__link>", new IPV6_AST_NULL());
				}
				else return new IPV6_AST_ERROR(0, "unexpect token type", new IPV6_AST_NULL());
			}
			else return new IPV6_AST_ERROR(0, "unexpect token type", new IPV6_AST_NULL());
	}

	IPV6_AST* parse_ipv6_ip(TOKEN_STREAM& token, size_t& pointer) {
		std::cout << "parse_ipv6_ip" << std::endl;

			if (token[pointer].first == IPV6_TOKEN_TYPE::DOUBLE_COLON_TYPE || token[pointer].first == IPV6_TOKEN_TYPE::DIGIT_TYPE) {
				//.link [end]
				IPV6_AST* ast = parse_ipv6_link(token, pointer);
				if (ast->is_error()) return new IPV6_AST_ERROR(0, "cant match <link>", ast);
				else if (token[pointer].first != IPV6_TOKEN_TYPE::END_TYPE) {
					return new IPV6_AST_ERROR(0, "except a [end]", ast);
				}
				else {
					pointer++;
					return new IPV6_AST_IP(ast);
				}
			}
			else {
				if(token[pointer].first == IPV6_TOKEN_TYPE::END_TYPE) return new IPV6_AST_ERROR(0, "unexcept [end]", new IPV6_AST_NULL());
				else if (token[pointer].first == IPV6_TOKEN_TYPE::ERROR_TYPE) return new IPV6_AST_ERROR(0, "error token type", new IPV6_AST_NULL());
				else return new IPV6_AST_ERROR(0, "unexcept token type", new IPV6_AST_NULL());
			}
	}

	IP::TYPE ip_type(const std::string_view& ip) {

		enum STATE {
			UNKNOW_ERROR = 0,

			IPV4_START,
			IPV4_NUM_1,
			IPV4_NUM_1_dot,
			IPV4_NUM_2,
			IPV4_NUM_2_dot,
			IPV4_NUM_3,
			IPV4_NUM_3_dot,
			IPV4_NUM_4,
			IPV4_UNEXP_END,
			IPV4_ACCEPT,
			IPV4_ERROR,

			IPV6_START,
			IPV6_COLON,
			IPV6_DOUBULE_COLON,
			IPV6_END,
			IPV6_ERROR
		};
		IP::TYPE ret = IP::TYPE::error_type;
		int state = UNKNOW_ERROR;

		size_t size = ip.size();
		if (size > 39 || size < 2) return  ret;

		for (auto var : ip) {
			if (var == '.') {
				state = IPV4_START;
				break;
			}
			else if (var == ':') {
				state = IPV6_START;
				break;
			}
		}
		if (state == UNKNOW_ERROR) return ret;

		//	std::array < std::pair<size_t, size_t>, 4> number_pointer{ {{0,0},{0,0},{0,0},{0,0}} };

		size_t i = 0;
		bool error_ret = false;
		bool accept = false;


		if (state == STATE::IPV4_START) {
			std::array<size_t, 4> number{ 0,0,0,0 };
			while (!(error_ret || accept)) {
				switch (state) {
				case STATE::IPV4_START:
					if (i == size) {
						state = STATE::IPV4_UNEXP_END;
					}
					else if (is_digit_0_9(ip[i])) {
						number[0] = ip[i++] - '0';
						state = STATE::IPV4_NUM_1;
					}
					else {
						state = STATE::IPV4_ERROR;
					}
					break;

				case STATE::IPV4_NUM_1:
					if (i == size) {
						state = STATE::IPV4_UNEXP_END;
					}
					else if (is_digit_0_9(ip[i])) {
						number[0] = number[0] * 10 + ip[i++] - '0';
					}
					else if (ip[i] == '.') {
						i++;
						state = STATE::IPV4_NUM_1_dot;
					}
					else {
						state = STATE::IPV4_ERROR;
					}
					break;

				case STATE::IPV4_NUM_1_dot:
					if (i == size) {
						state = STATE::IPV4_UNEXP_END;
					}
					else if (is_digit_0_9(ip[i])) {
						number[1] = ip[i++] - '0';
						state = STATE::IPV4_NUM_2;
					}
					else {
						state = STATE::IPV4_ERROR;
					}
					break;

				case STATE::IPV4_NUM_2:
					if (i == size) {
						state = STATE::IPV4_UNEXP_END;
					}
					else if (is_digit_0_9(ip[i])) {
						number[1] = number[1] * 10 + ip[i++] - '0';
					}
					else if (ip[i] == '.') {
						i++;
						state = STATE::IPV4_NUM_2_dot;
					}
					else {
						state = STATE::IPV4_ERROR;
					}
					break;

				case STATE::IPV4_NUM_2_dot:
					if (i == size) {
						state = STATE::IPV4_UNEXP_END;
					}
					else if (is_digit_0_9(ip[i])) {
						number[2] = ip[i++] - '0';
						state = STATE::IPV4_NUM_3;
					}
					else {
						state = IPV4_ERROR;
					}
					break;

				case STATE::IPV4_NUM_3:
					if (i == size) {
						state = STATE::IPV4_UNEXP_END;
					}
					else if (is_digit_0_9(ip[i])) {
						number[2] = number[2] * 10 + ip[i++] - '0';
					}
					else if (ip[i] == '.') {
						i++;
						state = STATE::IPV4_NUM_3_dot;
					}
					else {
						state = STATE::IPV4_ERROR;
					}
					break;

				case STATE::IPV4_NUM_3_dot:
					if (i == size) {
						state = STATE::IPV4_UNEXP_END;
					}
					else if (is_digit_0_9(ip[i])) {
						number[3] = ip[i++] - '0';
						state = STATE::IPV4_NUM_4;
					}
					else {
						state = STATE::IPV4_ERROR;
					}
					break;

				case STATE::IPV4_NUM_4:
					if (i == size) {
						state = STATE::IPV4_ACCEPT;
					}
					else if (is_digit_0_9(ip[i])) {
						number[3] = number[3] * 10 + ip[i++] - '0';
					}
					else {
						state = STATE::IPV4_ERROR;
					}
					break;

				case STATE::IPV4_UNEXP_END:
					error_ret = 1;
					break;

				case STATE::IPV4_ACCEPT:
					accept = 1;
					break;

				case STATE::IPV4_ERROR:
					error_ret = 1;
					break;

				default:
					break;
				}
			}
			if (accept) {
				for (auto var : number) {
					//					std::cout << var << " ";
					if (var > 255) return IP::error_type;
				}
				return IP::ipv4_type;
			}
			else return IP::error_type;
		}
		else if (state == IPV6_START) {
			using IPV6_PAIR = std::pair<int, int>;
			std::vector<IPV6_PAIR> token;
			bool token_end_flag = false;
			bool token_error = false;

			while (!token_end_flag) {
				switch (state) {
				case IPV6_START:
					if (i == size) {
						state = STATE::IPV6_END;
					}
					else if (is_digit_0_9(ip[i]) || is_a_f(ip[i]) || is_A_F(ip[i])) {
						token.push_back(IPV6_PAIR(IPV6_TOKEN_TYPE::DIGIT_TYPE, ip[i]));
						i++;
					}
					else if (ip[i] == ':') {
						i++;
						state = STATE::IPV6_COLON;
					}
					else {
						state = STATE::IPV6_ERROR;
					}
					break;

				case IPV6_COLON:
					if (i == size) {
						token.push_back(IPV6_PAIR(IPV6_TOKEN_TYPE::COLON_TYPE, 0));
						state = STATE::IPV6_END;
					}
					else if (ip[i] == ':') {
						token.push_back(IPV6_PAIR(IPV6_TOKEN_TYPE::DOUBLE_COLON_TYPE, 0));
						i++;
						state = STATE::IPV6_START;
					}
					else
					{
						token.push_back(IPV6_PAIR(IPV6_TOKEN_TYPE::COLON_TYPE, 0));
						state = STATE::IPV6_START;
					}
					break;

				case IPV6_END:
					token.push_back(IPV6_PAIR(IPV6_TOKEN_TYPE::END_TYPE, 0));
					token_end_flag = true;
					break;

				case IPV6_ERROR:
					token_end_flag = true;
					token_error = true;
					break;

				default:
					break;
				}
			}

			if (token_error) return net::IP::error_type;
			std::string type_str[6]{ "ERROR_TYPE","DIGIT_TYPE","COLON_TYPE","DOUBLE_COLON_TYPE","END_TYPE" };
			std::cout << "prnt token" << std::endl;
			for (IPV6_PAIR& var : token) {
				std::cout << type_str[var.first] << ":" << static_cast<char>(var.second) << " ";
			}
			std::cout << std::endl << "print ast:" << std::endl;

			size_t token_pointer = 0;
			IPV6_AST* ipv6_ast = parse_ipv6_ip(token, token_pointer);
			if (ipv6_ast->is_error()) {
				std::cout << "parse error" << std::endl;
				ipv6_ast->print_ast();
				return net::IP::error_type;
			}
			else {
				std::cout << "parse success" << std::endl;
				ipv6_ast->print_ast();
				return net::IP::ipv6_type;
			}


		}

		std::cout << "error flow";

	}


}