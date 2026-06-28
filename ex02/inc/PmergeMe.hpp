#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <vector>
#include <iostream>

class PmergeMe {

public:
	static void printVec(std::vector<int> v)
	{
		std::cout << "[";
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		{
			std::cout << *it;
			if (it + 1 != v.end())
				std::cout << ";";
		}
		std::cout << "]" << std::endl;
	}

	template<typename T> T fordJohnson(T data)
	{

		std::vector<int> indices;

		for (size_t i = 0; i < data.size(); i++)
		{
			std::cout << data[i] << std::endl;
			indices.push_back(i);
		}

		indices = pairAndSplit(data, indices);

		for (size_t i = 0; i < indices.size(); i++)
		{
			std::cout << data[indices[i]] << std::endl;
		}
		return indices;
	}

private:
	std::vector<int> createJacobSthalSequence(int range);
	template<typename T> T insertInChain(T chain, float number);

	std::vector<int> pairAndSplit(std::vector<int> data, std::vector<int> indices)
	{
		if (indices.size() == 1)
			return (indices);

		/* contains pairs of indexes for the current recursion level.*/

		/* winChain and loseChain contain indices of their corresponding value in data[]. */

		std::vector<int>	winChain;
		std::vector<int>	loseChain;

		std::cout << "pairAndSplit with indices :";
		printVec(indices);
		int straggler = -1;
		bool hasStraggler = false;
		if (indices.size() % 2 != 0)
		{
			straggler = indices.back();
			hasStraggler = true;
			indices.pop_back();
		}

		for (size_t i = 0; i < indices.size() - 1; i +=2)
		{
			std::pair<int, int> p;

			// std::cout << "data:";
			// printVec(data);
			// std::cout << "winchain";
			// printVec(winChain);
			// std::cout << "indices :";
			// printVec(indices);

			if (data[indices[i]] < data[indices[i+1]])
			{
				p.first = i;
				p.second = i + 1;
				winChain.push_back(indices[i + 1]);
				loseChain.push_back(indices[i]);
				std::cout << "index " << indices[i] << "(value " << data[indices[i]] << ") lost to index " << indices[i + 1] << " (value " << data[indices[i + 1]] <<  ")" << std::endl;
			}
			else
			{
				p.first = i + 1;
				p.second = i;
				winChain.push_back(indices[i]);
				loseChain.push_back(indices[i + 1]);
				std::cout << "index " << indices[i + 1] << "(value " << data[indices[i + 1]] << ") lost to index " << indices[i] << " (value " << data[indices[i]] << ")" << std::endl;
			}
		}

		winChain = pairAndSplit(data, winChain);

		/* insert the losers in a newWinChain to avoid losing loser / winner bond */
		std::vector<int> newWinChain(winChain); std::cout << "Winchain before insertions : ";
		printVec(newWinChain);

		std::vector<int> jacobSthalSeq = createJacobSthalSequence(loseChain.size()); // 0, 1, 3, 2, 5, 4 etc
		
		std::cout << "Loser chain size : " << loseChain.size() << std::endl;
		for (std::vector<int>::iterator currentLoserIndex = jacobSthalSeq.begin(); currentLoserIndex != jacobSthalSeq.end(); ++currentLoserIndex)
		{
			// For each number in jacob sequence,
			// take the corresponding value in loseChain (which is the index in data to the losing number)
			// and perform a binary search in winChain to know where to put it.
			// The binary search needs to compare the actual values (in data) in order to put the losing index in the correct
			// spot in winChain.
			// The binary search is always performed between winChain[0] and winChain[k] where k is the index of current loser's bonded winner.
			// std::find() can be used to find the bonded winner in the now-modified winChain, byut in order to do this we need to know the actual winner value.
			//
			int winnerIdx = winChain[*currentLoserIndex];
			std::vector<int>::iterator bondedWinner = std::find(newWinChain.begin(), newWinChain.end(), winnerIdx);

			std::cout << "upper bound in newWinChain between " << *newWinChain.begin() << " and " << *bondedWinner << std::endl;
			std::cout << "inserting loser " << *(loseChain.begin() + *currentLoserIndex) << " (value "<< data[*currentLoserIndex] << ") in winChain" << std::endl;


			std::vector<int>::iterator low = newWinChain.begin();
			std::vector<int>::iterator high = bondedWinner;
			while (low != high)
			{
				int difference = high - low;
				std::vector<int>::iterator mid = low + difference / 2;
				if (data[*mid] < data[loseChain[*currentLoserIndex]])
					low += difference / 2;
				else
					high = low + difference / 2;
			}
			newWinChain.insert(low, loseChain[*currentLoserIndex]);

		}
		if (hasStraggler)
		{
			std::vector<int>::iterator low = newWinChain.begin();
			std::vector<int>::iterator high = newWinChain.end();
			while (low != high)
			{
				int difference = high - low;
				std::vector<int>::iterator mid = low + difference / 2;
				if (data[*mid] < data[straggler])
					low = mid + 1;
				else
					high = mid;
			}
			newWinChain.insert(low, straggler);
		}

		return (newWinChain);
	}
};

#endif
