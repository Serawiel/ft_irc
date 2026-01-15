#include "RPN.hpp"

RPN::RPN() : _list()
{
}

RPN::RPN(const RPN &src) : _list(src._list)
{
}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		_list = rhs._list;
	}
	return (*this);
}

RPN::~RPN()
{
}

void RPN::calculate(std::string const &str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			continue ;

		if (str[i] >= '0' && str[i] <= '9')
		{
			_list.push_back(str[i] - '0');
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*'
			|| str[i] == '/')
		{
			if (_list.size() < 2)
			{
				std::cout << "Error" << std::endl;
				return ;
			}

			int b = _list.back();
			_list.pop_back();
			int a = _list.back();
			_list.pop_back();

			int result;
			switch (str[i])
			{
			case '+':
				result = a + b;
				break ;
			case '-':
				result = a - b;
				break ;
			case '*':
				result = a * b;
				break ;
			case '/':
				if (b == 0)
				{
					std::cout << "Error: division by 0" << std::endl;
					exit (1);
				}
				result = a / b;
				break ;
			}
			_list.push_back(result);
		}
		else
		{
			std::cout << "Error" << std::endl;
			return ;
		}
	}
	if (_list.size() != 1)
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	std::cout << _list.back() << std::endl;
}