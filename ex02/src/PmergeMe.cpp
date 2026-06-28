#include <vector>
#include "PmergeMe.hpp"
/**
 * @brief creates a jacobsthal insertion sequence for a given range.
 * @param range the size of the losing chain (max index of element to be inserted)
 * @returns a vector of indexes to be inserted in JacobSthal order.
 */
std::vector<int> PmergeMe::createJacobSthalSequence(int range)
{
	std::vector<int> seq;
	seq.push_back(0);
	if (range > 1)
		seq.push_back(1);
	int prev = 1;
	int prev2 = 0;
	for (int a = 2; a < range; ++a)
	{
		int nextNumber = prev + prev2 * 2;

		for (int i = nextNumber; i > prev; --i)
		{
			seq.push_back(i);
		}

		prev = seq[seq.size() - 1];
		prev2 = seq[seq.size() - 2];
	}

	std::cout << "jacob : ";
	printVec(seq);
	return (seq);
}
