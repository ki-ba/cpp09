#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>

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
	static bool validateTime(const std::string &time_str);
	void extractComponents(std::string &line, std::string &str_date, double &amount);

	void readDatabase(const std::string &filename);
	void readAmounts(const std::string &filename);
	double calculateNextValue();
};

#endif
