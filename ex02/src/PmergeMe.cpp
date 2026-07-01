#include <vector>
#include <deque>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<size_t> numbers)
{
	gettimeofday(&start_time, NULL);
	for (std::vector<size_t>::iterator it = numbers.begin(); it != numbers.end(); ++it)
		this->numbers_vector.push_back(*it);

	this->fordJohnson<std::vector<size_t> >(numbers_vector);
	std::cout << std::endl;
	std::cout << "vector time elapsed (size " << numbers_vector.size() << " ): " << this->getElapsedTime() << " us" << std::endl;
	std::cout << std::endl;

	gettimeofday(&start_time, NULL);
	for (std::vector<size_t>::iterator it = numbers.begin(); it != numbers.end(); ++it)
		this->numbers_deque.push_back(*it);

	this->fordJohnson<std::deque<size_t> >(numbers_deque);
	std::cout << std::endl;
	std::cout << "deque time elapsed (size " << numbers_deque.size() << "): " << this->getElapsedTime() << " us" << std::endl;
	std::cout << std::endl;
}
