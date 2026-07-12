#include <algorithm>
#include <limits.h>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>
#include "PmergeMe.hpp"

int usage()
{
	std::cerr << "usage : ./PmergeMe \"n1 n2 ... nk\"" << std::endl;
	return (2);
}

int parsing(std::stringstream &input, std::vector<size_t> &numbers)
{
	std::string	number_str;
	double		number;

	while(std::getline(input, number_str, ' '))
	{
		std::stringstream number_stream(number_str);
		number_stream >> number;
		if (number > INT_MAX)
		{
			std::cout << "number too big" << std::endl;
			return (PARSING_ERROR);
		}
		if (static_cast<size_t>(number) != number)
		{
			std::cout << ASCII_ART_NAN << std::endl;
			std::cout << "not an integer" << std::endl;
			return (PARSING_ERROR);
		}
		if (number_stream.fail() || !number_stream.eof())
		{
			std::cout << ASCII_ART_NAN << std::endl;
			std::cout << "me when i put a non-number in the number sorting program" << std::endl;
			return (PARSING_ERROR);
		}

		if (number < 0)
		{
			std::cout << ASCII_ART_NEGATIVES << std::endl;
			std::cout << "no negative numbers pls" << std::endl;
			return (PARSING_ERROR);
		}

		if (std::find(numbers.begin(), numbers.end(), number) != numbers.end())
			continue;
		numbers.push_back(number);

	}

	if (numbers.size() == 0)
		{
			std::cout << ASCII_ART_EMPTY << std::endl;
			std::cout << "no numbers to sort" << std::endl;
			return (PARSING_ERROR);
		}

	return (0);

}

int main(int argc, char *argv[])
{
	if (argc < 2)
		return (usage());

	std::stringstream	input;
	std::vector<size_t>	numbers;

	input << argv[1];
	for (int i = 2; i < argc; ++i)
	{
		input << " " << argv[i];
	}
	int parsingStatus = parsing(input, numbers);

	if (parsingStatus != 0)
		return (parsingStatus);

	PmergeMe sorter(numbers);

	return (0);
}
