#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>

struct		Pair
{
	int		large;
	int		small;
};

class PmergeMeVector
{
  private:
	std::vector<Pair> _pairs;
	std::vector<int> _larges;
	std::vector<int> _result;
	int		_aloneNb;
	bool	_hasAloneNb;

	void createPairs(std::string const &str);
	void sortLarger();
	void insertSmaller();

  public:
	PmergeMeVector();
	PmergeMeVector(PmergeMeVector const &src);
	PmergeMeVector const &operator=(PmergeMeVector const &src);
	~PmergeMeVector();

	void sort();
};

class ErrorException : public std::exception
{
  public:
	virtual const char *what() const throw();
};

#endif