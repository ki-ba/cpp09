#ifndef RPN_HPP
# define RPN_HPP

#include <stack>

class RPN
{
private:
	std::stack<float> expr;
	
public:
	RPN();
	~RPN();
	void	eatChar(char c);
	float	result();
};

#endif
