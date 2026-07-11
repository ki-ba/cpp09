/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:01:11 by kbarru            #+#    #+#             */
/*   Updated: 2026/05/05 16:22:28 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	if (&other == this)
		return ;
	this->prices = other.prices;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (&other == this)
		return (*this);
	this->prices = other.prices;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::validateTime(const std::string &time_str)
{
		struct tm	datetime = {0,0,0,0,0,0,0,0,0,0,0};
		char		time_check[50] = {0};

		if (time_str.length() < 10)
			return false;
		strptime(time_str.c_str(), "%Y-%m-%d", &datetime);
		datetime.tm_isdst = -1;

		std::mktime(&datetime);
		strftime(time_check, 50, "%Y-%m-%d", &datetime);

		return (time_str == time_check);
}

void BitcoinExchange::extractComponents(std::string &line, std::string &str_date, double &amount)
{
	size_t	delim = line.find('|');
	size_t	delim2 = delim;

	if (delim == line.npos)
		throw std::runtime_error("Incorrect format");

	while (delim > 0 && line[delim - 1] == ' ')
		--delim;

	str_date = line.substr(0, delim);
	
	if (!this->validateTime(str_date))
		throw std::runtime_error("Invalid date : " + str_date);

	while (line[delim2] == ' ')
			++delim2;

	amount = atof(line.substr(delim2 + 1).c_str());

	if (amount < 0)
		throw std::runtime_error("Not a positive number");

	if (amount > 1000)
		throw std::runtime_error("Too big a number");
}

void BitcoinExchange::readDatabase(const std::string &filename)
{
	std::ifstream db_file(filename.c_str());
	bool is_first_line = true;

	this->prices.clear();

	if (!db_file.is_open())
		throw std::runtime_error("Can't open database");

	for (std::string cur_line; std::getline(db_file, cur_line);)
	{
		if (cur_line == "date,exchange_rate" && is_first_line)
		{
			is_first_line = false;
			continue;
		}

		is_first_line = false;
		try
		{
			this->addEntry(cur_line);
		}
		catch (std::runtime_error &e)
		{
			std::cerr << "[db] Error : " << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::addEntry(const std::string &entry)
{
	size_t	delim_index = entry.find(',');
	std::string str_date = entry.substr(0, delim_index);
	std::string str_val = entry.substr(delim_index + 1);


	if (!validateTime(str_date))
		throw std::runtime_error("Invalid date : " + str_date);
	if (atof(str_val.c_str()) < 0)
		throw std::runtime_error("Not a positive number");
	prices.insert(std::make_pair(str_date, atof(str_val.c_str())));
}

double	BitcoinExchange::getBTCPrice(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = this->prices.lower_bound(date);
	if (date != it->first)
	{
		if (it == this->prices.begin())
			throw std::runtime_error("No known BTC price for that date");
		--it;
	}
	return (it->second);
}

double	BitcoinExchange::getValue(const std::string &date, const double &amount) const
{
	double	btcValue;
	try
	{
		btcValue = this->getBTCPrice(date);
	}
	catch(std::runtime_error &e)
	{
		throw std::runtime_error(e.what());
	}

	return (amount * btcValue);
}

void BitcoinExchange::readAmounts(const std::string &filename)
{

	std::ifstream user_file(filename.c_str());

	if (!user_file.is_open())
		throw std::runtime_error("Can't open user file");

	for (std::string cur_line; std::getline(user_file, cur_line);)
	{
		double		amount = 0;
		double		total = 0;
		bool		is_first_line = true;
		std::string str_date;

		if (is_first_line && (cur_line == "date | value" || cur_line == "date|value"))
		{
			is_first_line = false;
			continue;
		}

		is_first_line = false;
		if (cur_line[0] == '#')
			continue ;

		try
		{
			this->extractComponents(cur_line, str_date, amount);
			total = this->getValue(str_date, amount);
			std::cout << str_date << " => " << amount << " : " << total << std::endl;
		}
		catch (std::runtime_error &e)
		{
			std::cerr << "[user file] Error : " << e.what() << std::endl;
			continue;
		}
	}
}
