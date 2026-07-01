#include <algorithm>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "PmergeMe.hpp"

int usage()
{
	std::cerr << "usage : ./PmergeMe \"n1 n2 ... nk\"" << std::endl;
	return (2);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (usage());

	PmergeMe			sort;
	std::stringstream	input(argv[1]);
	std::string			number_str;
	double number;

	std::vector<size_t>	numbers_vector;
	std::deque<size_t>	numbers_deque;

	while(std::getline(input, number_str, ' '))
	{
		std::stringstream number_stream(number_str);
		number_stream >> number;
		numbers_vector.push_back(number);
		numbers_deque.push_back(number);
	}

	sort.fordJohnson<std::vector<size_t> >(numbers_vector);

	// for (std::vector<double>::iterator it = numbers_vector.begin(); it != numbers_vector.end(); ++it)
	// {
	// 	std::cout << *it << std::endl;
	// }
	//
	// for (std::deque<double>::iterator it = numbers_deque.begin(); it != numbers_deque.end(); ++it)
	// {
	// 	std::cout << *it << std::endl;
	// }
	return (0);
}
