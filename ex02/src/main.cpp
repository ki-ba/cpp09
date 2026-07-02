#include <algorithm>
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
		if (number_stream.fail() || !number_stream.eof())
		{
			std::cout << ASCII_ART_NAN << std::endl;
			std::cout << "me when i put a non-number in the number sorting program" << std::endl;
			return (PARSING_ERROR);
		}

		if (number < 0)
		{
			std::cout << "oh no... is that... a negative number????" << std::endl;
			sleep(2);
			std::cout << "i can't handle this!!!" << std::endl;
			sleep(2);
			std::cout << ASCII_ART_NEGATIVES << std::endl;
			sleep(3);
			std::cout << "just kidding but stop now" << std::endl;
			return (PARSING_ERROR);
		}

		if (std::find(numbers.begin(), numbers.end(), number) != numbers.end())
		{
			std::cout << "skipping duplicate number: " << number << std::endl;
			continue;
		}
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
	if (argc != 2)
		return (usage());

	std::stringstream	input(argv[1]);
	std::vector<size_t>	numbers;

	int parsingStatus = parsing(input, numbers);

	if (parsingStatus != 0)
		return (parsingStatus);

	PmergeMe sorter(numbers);

	return (0);
}
