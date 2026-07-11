#include "RPN.hpp"
#include <cctype>
#include <cstring>
#include <stdexcept>

RPN::RPN() {}
RPN::RPN(const RPN &other) : expr(other.expr) {}
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->expr = other.expr;
	return (*this);
}
RPN::~RPN() {}

void RPN::eatChar(char c)
{
	if (std::isdigit(c))
	{
		this->expr.push(c - '0');
		return ;
	}

	if (this->expr.size() < 2)
		throw std::runtime_error("Invalid syntax : early symbol");

	float n1 = expr.top();
	this->expr.pop();

	float n2 = expr.top();
	this->expr.pop();

	if (!std::strchr("+-*/", c))
		throw std::runtime_error("Invalid syntax : unknown symbol");
	if (c == '*')
		this->expr.push(n1 * n2);
	else if (c == '/')
	{
		if (n1 == 0)
			throw std::runtime_error("Invalid syntax : division by 0");
		this->expr.push(n2 / n1);
	}
	else if (c == '-')
		this->expr.push(n2 - n1);
	else if (c == '+')
		this->expr.push(n1 + n2);
}

float RPN::result()
{
	if (this->expr.empty())
		return (0);
	if (this->expr.size() > 1)
		throw (std::runtime_error("Invalid syntax : remaining digits not associated with symbol"));
	return (this->expr.top());
}
