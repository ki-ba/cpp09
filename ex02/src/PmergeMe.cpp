#include <vector>
#include "PmergeMe.hpp"
/**
 * @brief creates a jacobsthal insertion sequence for a given range.
 * @param range the size of the losing chain (max index of element to be inserted)
 * @returns a vector of indexes to be inserted in JacobSthal order.
 */
std::vector<size_t> PmergeMe::createJacobSthalSequence(size_t n)
{
	std::vector<size_t> jacob;
	std::vector<size_t> seq;


	std::cout << "running createJacob with n = " << n << std::endl;
	/* First, generate the Jacobsthal numbers up to n. */

	if (n <= 1)
	{
		std::cout << "insertion sequence : ";
		printVec(seq);
		return seq;
	}
	jacob.push_back(1);
	jacob.push_back(3);

	while (jacob.back() < n - 1)
		jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

	/* Then, generate the Jacobsthal insertion sequence. */

	size_t	prev = 0;

	for (size_t i = 0; i < jacob.size(); ++i)
	{
		size_t	hi = std::min(jacob[i], n - 1);
		for (size_t j = hi; j > prev; --j)
			seq.push_back(j);
		if (hi >= n - 1)
			break;
		prev = jacob[i];
	}

	// std::cout << "jacob : ";
	// printVec(jacob);
	std::cout << "insertion sequence : ";
	printVec(seq);
	return (seq);
}
