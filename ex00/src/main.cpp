/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:02:20 by kbarru            #+#    #+#             */
/*   Updated: 2026/05/05 16:38:38 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#define USAGE "usage : ./btc <amounts_file>"
#define USAGE_RETURN_VALUE 2
#define ERR_RETURN_VALUE 1
#define DATABASE_FILENAME "data.csv"

#include <iomanip>
#include <iostream>
#include "BitcoinExchange.hpp"

int usage(int status)
{
	std::cerr << USAGE << std::endl;
	return (status);
}

int main(int argc, char *argv[])
{
	std::cout << std::setprecision(10);
	if (argc != 2)
		return (usage(USAGE_RETURN_VALUE));
	
	std::string filename(argv[1]);
	BitcoinExchange interpreter;

	try
	{
		
		interpreter.readDatabase(DATABASE_FILENAME);
		interpreter.readAmounts(filename);
	}
	catch (std::runtime_error &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return (ERR_RETURN_VALUE);
	}

	return (0);
}
