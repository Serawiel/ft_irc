#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	std::cout << "Before: ";
	if (argc - 1 <= 4)
	{
		for (int i = 1; i < argc; i++)
			std::cout << " " << argv[i];
	}
	else
	{
		for (int i = 1; i <= 4; i++)
			std::cout << " " << argv[i];
		std::cout << "[...]";
	}
	std::cout << std::endl;
	try
	{
		PmergeMeVector pmv;
		clock_t startV = clock();
		std::vector<int> resultV = pmv.sort(argc, argv);
		std::cout << "After: ";
		if (resultV.size() <= 4)
			std::cout << resultV << std::endl;
		else
		{
			for (size_t i = 0; i < 4; i++)
				std::cout << resultV[i] << " ";
			std::cout << "[...]" << std::endl;
		}
		clock_t endV = clock();
		double timeV = (double)(endV - startV) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << (argc
			- 1) << " elements with std::vector : " << timeV << " us" << std::endl;

		PmergeMeDeque pmd;
		clock_t startD = clock();
		std::deque<int> resultD = pmd.sort(argc, argv);
		clock_t endD = clock();
		double timeD = (double)(endD - startD) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << (argc
			- 1) << " elements with std::deque : " << timeD << " us" << std::endl;
	}
	catch (ErrorException &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}