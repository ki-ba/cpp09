/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 11:57:33 by kbarru            #+#    #+#             */
/*   Updated: 2026/07/12 12:16:23 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
private:
	std::map<std::string, double> prices;

public:
	BitcoinExchange();
	BitcoinExchange(const std::string &filename);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void	addEntry(const std::string &entry);
	void	displayEntries();
	double	getBTCPrice(const std::string &date) const;
	double	getValue(const std::string &date, const double &amount) const;
	bool validateTime(const std::string &time_str);
	void extractComponents(std::string &line, std::string &str_date, double &amount);

	void readDatabase(const std::string &filename);
	void readAmounts(const std::string &filename);
	double calculateNextValue();
};

#endif
