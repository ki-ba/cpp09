#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

class PmergeMe
{
	public:
		/* Functor : used by upper_bound */
		struct CompareByValue
		{
			const std::vector<size_t>& seq;
			CompareByValue(const std::vector<size_t>& s) : seq(s) {}
			bool operator()(std::size_t a, std::size_t b) const {
				return seq[a] < seq[b];
			}
		};

		static void printVec(std::vector<size_t> v)
		{
			std::cout << "[";
			for (std::vector<size_t>::iterator it = v.begin(); it != v.end(); ++it)
			{
				std::cout << *it;
				if (it + 1 != v.end())
					std::cout << ";";
			}
			std::cout << "]" << std::endl;
		}

		static void printVec(std::vector<size_t> v, std::vector<size_t> data)
		{
			std::cout << "[";
			for (std::vector<size_t>::iterator it = v.begin(); it != v.end(); ++it)
			{
				std::cout << *it << " (" << data[*it] << ") ";
				if (it + 1 != v.end())
					std::cout << ";";
			}
			std::cout << "]" << std::endl;
		}

		template<typename T> T fordJohnson(T data)
		{
			std::vector<size_t> indices;
			std::vector<size_t> sortedData;

			for (size_t i = 0; i < data.size(); i++)
				indices.push_back(i);

			std::cout << "Before :"; printVec(data);

			indices = pairAndSplit(data, indices);

			for (size_t i = 0; i < indices.size(); i++)
				sortedData.push_back(data[indices[i]]);

			std::cout << "After: "; printVec(sortedData);

			return indices;
		}

	private:
		std::vector<size_t> createJacobSthalSequence(int range);
		template<typename T> T insertInChain(T chain, float number);

		std::vector<size_t> pairAndSplit(std::vector<size_t> data, std::vector<size_t> indices)
		{
			if (indices.size() == 1)
				return (indices);

			std::vector<size_t>	winChain;
			std::vector<size_t>	loseChain;

			int straggler = -1;
			bool hasStraggler = indices.size() % 2 != 0;

			if (hasStraggler)
			{
				straggler = indices.back();
				indices.pop_back();

				// std::cout << "Straggler : " << straggler << std::endl;
			}
			// else
			// 	std::cout << "No straggler" << std::endl;

			for (size_t i = 0; i < indices.size() - 1; i +=2)
			{
				if (data[indices[i]] < data[indices[i+1]])
				{
					winChain.push_back(indices[i + 1]);
					loseChain.push_back(indices[i]);
				}
				else
				{
					winChain.push_back(indices[i]);
					loseChain.push_back(indices[i + 1]);
				}
			}

			winChain = pairAndSplit(data, winChain);

			/* insert the losers in a newWinChain to avoid losing loser / winner bond */
			std::vector<size_t> newWinChain(winChain);
			// std::cout << "Winchain before insertions : ";
			// printVec(newWinChain, data);

			std::vector<size_t> jacobSthalSeq = createJacobSthalSequence(loseChain.size()); // 0, 1, 3, 2, 5, 4 etc

			std::vector<size_t> winnerPositions;
				
			for(std::vector<size_t>::iterator loser = loseChain.begin(); loser != loseChain.end(); ++loser)
				winnerPositions.push_back(std::distance(loseChain.begin(), loser));

			for (std::vector<size_t>::iterator currentLoserIndex = jacobSthalSeq.begin(); currentLoserIndex != jacobSthalSeq.end(); ++currentLoserIndex)
			{

				size_t element = loseChain[*currentLoserIndex];
				/* for n a position in loseChain, winnerPositions(n) the position of the bonded winner in the winChain. */
				
				std::vector<size_t>::iterator low = newWinChain.begin();
				std::vector<size_t>::iterator high = newWinChain.begin() + winnerPositions[*currentLoserIndex];

				CompareByValue comp(data);
				std::vector<std::size_t>::iterator insertPos = std::upper_bound(low, high, loseChain[*currentLoserIndex], comp);
		
				newWinChain.insert(insertPos, element);
				size_t insertedIndex = std::distance(newWinChain.begin(), insertPos);

				for (size_t i = insertedIndex; i < winChain.size(); ++i)
					++winnerPositions[i];
			}

			if (hasStraggler)
			{
				CompareByValue comp(data);
				std::vector<std::size_t>::iterator insertPos = std::upper_bound(newWinChain.begin(), newWinChain.end(), straggler, comp);
				newWinChain.insert(insertPos, straggler);
			}
			return (newWinChain);
		}
	};

#endif
