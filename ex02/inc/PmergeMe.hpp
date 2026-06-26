#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <vector>
#include <iostream>

class PmergeMe {

public:
	template<typename T> T fordJohnson(T list)
	{
		T winChain, loseChain;
		winChain = list;

		std::cout << "winChain :" << std::endl;
		for (size_t i = 0; i < winChain.size(); i++)
		{
			std::cout << winChain[i] << std::endl;
		}

		pairAndSplit(winChain, loseChain);
		return winChain;
	}


private:
	std::vector<int> createJacobSthalSequence(int range);
	template<typename T> T insertInChain(T chain, float number);

	template<typename T> T pairAndSplit(T winChain, T &loseChain)
	{
		T newWinChain;
		T newLoseChain;
		
		if (winChain.size() == 1)
			return (winChain);
		std::cout << "pair and Split" << std::endl;

		for (size_t i = 0; i < winChain.size() - 1; i +=2)
		{
			if (winChain[i] < winChain[i + 1])
			{
				newWinChain.push_back(winChain[i + 1]);
				newLoseChain.push_back(winChain[i]);
				if (loseChain.size() >= 2)
					std::swap(loseChain[i], loseChain[i + 1]);
			}
			else
			{
				newWinChain.push_back(winChain[i]);
				newLoseChain.push_back(winChain[i + 1]);
			}
		}

		pairAndSplit(newWinChain, newLoseChain);
		T loseChainCopy(newLoseChain);
		std::vector<int> jacobSthalSeq = createJacobSthalSequence(newLoseChain.size());
		size_t	loseSize = loseChain.size() - 1;
		size_t index = winChain.upper_bound(jacobSthalSeq[0], 0);
		newWinChain.insert(index, newLoseChain[index]);
		size_t	left_limit = 0;
		while (loseSize > 0)
		{
			size_t n = loseChain.size() - loseSize; // used to advance inside jacob seq
			index = winChain.upper_bound(jacobSthalSeq[n], 0);
			while (index > left_limit)
			{
				newWinChain.insert(index, newLoseChain[index]);
				--loseSize;
				--n;
			}
			left_limit = jacobSthalSeq[n];
		}
	}
};

#endif
