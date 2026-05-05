/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:15:55 by kbarru            #+#    #+#             */
/*   Updated: 2026/05/05 15:58:55 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_HPP
# define INTERPRETER_HPP

# include <fstream>
# include "Database.hpp"

class Interpreter
{
private:
	Interpreter();
	std::ifstream	file;

public:
	Interpreter(std::string filename);
	~Interpreter();
	double calculateNextValue(Database db);
	void readDatabase(Database db);
};

#endif
