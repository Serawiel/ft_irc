#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <set>
# include <sstream>
# include <utility>
# include <vector>
# include <deque>

class PmergeMeVector
{
  private:
	std::vector<int> mergeInsertSort(std::vector<int> input);
	std::vector<size_t> generateJacobsthal(size_t pendSize);
	
  public:
	PmergeMeVector();
	PmergeMeVector(PmergeMeVector const &src);
	PmergeMeVector const &operator=(PmergeMeVector const &src);
	~PmergeMeVector();

	std::vector<int> sort(int argc, char **argv);
};

class PmergeMeDeque
{
  private:
	std::deque<int> mergeInsertSort(std::deque<int> input);
	std::deque<size_t> generateJacobsthal(size_t pendSize);
	
  public:
	PmergeMeDeque();
	PmergeMeDeque(PmergeMeDeque const &src);
	PmergeMeDeque const &operator=(PmergeMeDeque const &src);
	~PmergeMeDeque();

	std::deque<int> sort(int argc, char **argv);
};

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec);

std::ostream& operator<<(std::ostream& os, const std::deque<int>& vec);

class ErrorException : public std::exception
{
  public:
	virtual const char *what() const throw();
};

#endif