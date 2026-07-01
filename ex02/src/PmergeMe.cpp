#include <vector>
#include "PmergeMe.hpp"
/**
 * @brief creates a jacobsthal insertion sequence for a given range.
 * @param range the size of the losing chain (max index of element to be inserted)
 * @returns a vector of indexes to be inserted in JacobSthal order.
 */
std::vector<size_t> PmergeMe::createJacobSthalSequence(int range)
{
	std::vector<size_t> jacobsthalNumbers;

	jacobsthalNumbers.push_back(0);

	/* First, generate the Jacobsthal numbers up to the range. */

	while (jacobsthalNumbers.back() < static_cast<size_t>(range))
	{
		if (jacobsthalNumbers.size() == 1)
			jacobsthalNumbers.push_back(1);
		else
		{
			int nextNumber = jacobsthalNumbers[jacobsthalNumbers.size() - 1] + jacobsthalNumbers[jacobsthalNumbers.size() - 2] * 2;
			jacobsthalNumbers.push_back(nextNumber);
		}
	}

	/* Then, generate the Jacobsthal insertion sequence. */

	std::vector<size_t> insertionSequence;
	insertionSequence.push_back(0);

	for (size_t i = 1; i < jacobsthalNumbers.size(); i++)
	{
		for (size_t j = jacobsthalNumbers[i]; j > jacobsthalNumbers[i - 1] && insertionSequence.size() < static_cast<size_t>(range); j--)
			insertionSequence.push_back(std::min(j, static_cast<size_t>(range - 1)));
	}

	while (insertionSequence.size() > static_cast<size_t>(range))
		insertionSequence.pop_back();


	// std::cout << "jacob : ";
	// printVec(jacobsthalNumbers);
	// std::cout << "insertion sequence : ";
	// printVec(insertionSequence);
	return (insertionSequence);
}
