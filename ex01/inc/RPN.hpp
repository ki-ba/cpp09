#ifndef RPN_HPP
# define RPN_HPP

#include <stack>

class RPN
{
private:
	std::stack<float> expr;
	
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();
	void	eatChar(char c);
	float	result();
};

#endif
