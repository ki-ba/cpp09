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
		std::vector<size_t> createJacobSthalSequence(size_t n);
		template<typename T> T insertInChain(T chain, float number);

		std::vector<size_t> pairAndSplit(std::vector<size_t> data, std::vector<size_t> indices)
		{
			if (indices.size() == 1)
				return (indices);

			std::vector<size_t>	winChain;
			std::vector<size_t>	loseChain;

			size_t	straggler = 0;
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

			std::vector<size_t> partnerLoser(data.size());

			/* Maintain the loser/winner bond by representing it by value (index in data, not position in the chain) */

			for (size_t i = 0; i < winChain.size(); ++i)
				partnerLoser[winChain[i]] = loseChain[i];

			std::vector<size_t> newWinChain = pairAndSplit(data, winChain);

			std::vector<size_t> orderedLosers(loseChain.size());

			for (size_t i = 0; i < loseChain.size(); ++i)
				orderedLosers[i] = partnerLoser[newWinChain[i]];

			/* insert the losers in a newWinChain to avoid losing loser / winner bond */
			// std::cout << "Winchain before insertions : ";
			// printVec(newWinChain, data);

			newWinChain.insert(newWinChain.begin(), orderedLosers[0]);

			std::vector<size_t> jacobSthalSeq = createJacobSthalSequence(orderedLosers.size()); // 0, 1, 3, 2, 5, 4 etc

			std::vector<size_t> winnerPositions;
				
			for(std::vector<size_t>::iterator loser = orderedLosers.begin(); loser != orderedLosers.end(); ++loser)
				winnerPositions.push_back(std::distance(orderedLosers.begin(), loser) + 1);

			for (std::vector<size_t>::iterator currentLoserIndex = jacobSthalSeq.begin(); currentLoserIndex != jacobSthalSeq.end(); ++currentLoserIndex)
			{

				size_t element = orderedLosers[*currentLoserIndex];
				
				std::vector<size_t>::iterator low = newWinChain.begin();
				std::vector<size_t>::iterator high = newWinChain.begin() + winnerPositions[*currentLoserIndex];

				CompareByValue comp(data);
				std::vector<std::size_t>::iterator insertPos = std::upper_bound(low, high, element, comp);
		
				size_t insertedIndex = std::distance(newWinChain.begin(), insertPos);
				newWinChain.insert(insertPos, element);

				for (size_t k = 0; k < winnerPositions.size(); ++k)
				{
					if (winnerPositions[k] >= insertedIndex)
						++winnerPositions[k];
				}
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
