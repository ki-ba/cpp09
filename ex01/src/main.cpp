#include <stdexcept>
#include <string>
#include <iostream>
#include "RPN.hpp"

int usage()
{
	std::cerr << "Usage : ./rpn <expression>" << std::endl;
	return (2);
}

int main(int argc, char *argv[])
{
	RPN expression;
	if (argc != 2)
		return (usage());
	std::string str(argv[1]);
	try
	{
		for (std::string::iterator c = str.begin(); c != str.end(); ++c)
		{
			if (*c == ' ')
				continue;
			expression.eatChar(*c);
		}
		std::cout << expression.result() << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
