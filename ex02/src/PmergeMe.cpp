#include <vector>
#include <deque>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<size_t> &numbers)
{
	gettimeofday(&start_time, NULL);
	for (std::vector<size_t>::iterator it = numbers.begin(); it != numbers.end(); ++it)
		this->numbers_vector.push_back(*it);


	std::vector<size_t> sortedNumbers = this->fordJohnson<std::vector<size_t> >(numbers_vector);

	std::cout << "Before: "; printVec(numbers);
	std::cout << "After: "; printVec(sortedNumbers, numbers);
	std::cout << "vector time elapsed (size " << numbers_vector.size() << "): " << this->getElapsedTime() << " us" << std::endl;

	gettimeofday(&start_time, NULL);
	for (std::vector<size_t>::iterator it = numbers.begin(); it != numbers.end(); ++it)
		this->numbers_deque.push_back(*it);

	this->fordJohnson<std::deque<size_t> >(numbers_deque);
	std::cout << "deque time elapsed (size " << numbers_deque.size() << "): " << this->getElapsedTime() << " us" << std::endl;
}

long PmergeMe::getElapsedTime() const
{
	return (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
}

