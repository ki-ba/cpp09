/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:01:11 by kbarru            #+#    #+#             */
/*   Updated: 2026/05/05 16:22:28 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>	
#include <stdexcept>
#include <stdlib.h>

Database::Database(std::string filename)
{
	std::string cur_line;
	std::ifstream db_file(filename.c_str());

	if (!db_file.is_open())
		throw std::runtime_error("Can't open database");

	std::getline(db_file, cur_line);
	for (std::string cur_line; std::getline(db_file, cur_line);)
	{
		try
		{
		this->addEntry(cur_line);
		}
		catch (std::runtime_error &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}
}
Database::~Database() {}

void Database::addEntry(const std::string entry)
{
	size_t	delim_index = entry.find(',');
	std::string str_date = entry.substr(0, delim_index);
	std::string str_val = entry.substr(delim_index + 1);
	char str_time[50];
	char time_check[50];

	struct tm datetime;

	strptime(str_date.c_str(), "%Y-%m-%d", &datetime);
	strftime(time_check, 50, "%Y-%m-%d", &datetime);

	if (std::string(time_check) != str_date)
		throw std::runtime_error("Invalid date");
	if (atof(str_val.c_str()) < 0)
		throw std::runtime_error("Value can't be negative");
	strftime(str_time, 50, "%Y-%m-%d", &datetime);
	prices.insert(std::make_pair(str_time, atof(str_val.c_str())));
}

void Database::displayEntries()
{
	std::map<std::string, double>::iterator it;
	std::cout << std::setprecision(8);
	for (it = prices.begin(); it != prices.end(); ++it)
	{
		std::cout << (*it).first << "," << (*it).second << std::endl;
	}	
}

double	Database::getBTCPrice(const std::string date) const
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

double	Database::getValue(const std::string date, const int amount) const
{
	int	btcValue;
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
