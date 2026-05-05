/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:18:00 by kbarru            #+#    #+#             */
/*   Updated: 2026/05/05 16:38:34 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Interpreter.hpp"
#include <stdexcept>
#include <cstdlib>
#include <iostream>

Interpreter::Interpreter(std::string filename) : file(filename.c_str())
{
	if (!this->file.is_open())
		throw std::runtime_error("Can't open user file");
}
Interpreter::~Interpreter() {}

void Interpreter::readDatabase(Database db)
{
	for (std::string cur_line; std::getline(this->file, cur_line);)
	{
		std::string	str_date;
		double		amount;
		double		total;
		char		time_check[50];

		struct tm	datetime;

		size_t	delim = cur_line.find('|');
		if (delim == str_date.npos)
		{
			std::cerr << "Error : Incorrect line detected" << std::endl;
			continue;
		}
		str_date = cur_line.substr(0, delim);


		strptime(str_date.c_str(), "%Y-%m-%d", &datetime);
		strftime(time_check, 50, "%Y-%m-%d", &datetime);

		if (std::string(time_check) != str_date)
		{
			std::cerr << "Error : Invalid date" << std::endl;
			continue;
		}
		amount = atof(cur_line.substr(delim + 1).c_str());
		if (amount < 0)
		{
			std::cerr << "Error : Amount can't be negative" << std::endl;
			continue;
		}
		try
		{
			total = db.getValue(str_date, amount);
			std::cout << str_date << " => " << amount << " : " << total << std::endl;
		}
		catch (std::runtime_error &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
			continue;
		}
	}
}
