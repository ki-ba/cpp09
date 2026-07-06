/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:58:48 by kbarru            #+#    #+#             */
/*   Updated: 2026/05/05 15:53:17 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_HPP
# define DATABASE_HPP

# include <map>
# include <string>

class Database
{
private:
	std::map<std::string, double> prices;
	Database();

public:
	Database(const std::string &filename);
	~Database();
	void addEntry(const std::string &entry);
	void	displayEntries();
	double	getBTCPrice(const std::string &date) const;
	double	getValue(const std::string &date, const double &amount) const;
};

#endif
