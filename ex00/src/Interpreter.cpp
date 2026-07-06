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
#include <cstdlib>
#include <iostream>

Interpreter::Interpreter(const std::string &filename) : file(filename.c_str())
{
	if (!this->file.is_open())
		throw std::runtime_error("Can't open user file");
}

Interpreter::~Interpreter() {}

void Interpreter::readDatabase(const Database &db)
{
	for (std::string cur_line; std::getline(this->file, cur_line);)
	{
		std::string	str_date = "";
		double		amount = 0;
		double		total = 0;
		char		time_check[50] = {0};
		int			is_first_line = 0;

		struct tm	datetime = {0,0,0,0,0,0,0,0,0,0,0};

		if (is_first_line++ == 0 && cur_line == "date | value" )
		{
			std::cerr << "[user file] ignoring first format line" << std::endl;
			continue;
		}

		if (cur_line[0] == '#')
			continue ;
		size_t	delim = cur_line.find('|');
		size_t	delim2 = delim;


		if (delim == cur_line.npos)
		{
			std::cerr << "[user file] Error : Incorrect line detected" << std::endl;
			continue;
		}

		while (delim > 0 && cur_line[delim - 1] == ' ')
			--delim;
		str_date = cur_line.substr(0, delim);


		strptime(str_date.c_str(), "%Y-%m-%d", &datetime);
		strftime(time_check, 50, "%Y-%m-%d", &datetime);

		if (std::string(time_check) != str_date)
		{
			std::cerr << "[user file] Error : Invalid date" << std::endl;
			continue;
		}

		while (cur_line[delim2] == ' ')
			++delim2;

		amount = atof(cur_line.substr(delim2 + 1).c_str());
		if (amount < 0 || amount > 1000)
		{
			std::cerr << "[user file] Error : amount must be between 0 and 1000" << std::endl;
			continue;
		}
		try
		{
			total = db.getValue(str_date, amount);
			if (total < 0)
				throw (std::runtime_error("Overflow detected"));
			std::cout << str_date << " => " << amount << " : " << total << std::endl;
		}
		catch (std::runtime_error &e)
		{
			std::cerr << "[user file] Error : " << e.what() << std::endl;
			continue;
		}
	}
}
