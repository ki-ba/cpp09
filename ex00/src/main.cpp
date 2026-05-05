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

#define USAGE "usage : ./btc <amounts_file>"
#define USAGE_RETURN_VALUE 2
#define DATABASE_FILENAME "data.csv"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Database.hpp"
#include "Interpreter.hpp"

int usage(int status)
{
	std::cerr << USAGE << std::endl;
	return (status);
}

int main(int argc, char *argv[])
{
	std::cout << std::setprecision(8);
	if (argc != 2)
		return (usage(USAGE_RETURN_VALUE));
	
	std::string filename(argv[1]);
	Interpreter interpreter(filename);
	Database db(DATABASE_FILENAME);

	std::cout << std::endl << std::endl;

	interpreter.readDatabase(db);
	return (0);
}
