#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		Base *ptr = generate();

		std::cout << "Test " << i + 1 << std::endl;
		std::cout << "  With pointer:   ";
		identify(ptr);
		std::cout << "  With reference: ";
		identify(*ptr);
		std::cout << std::endl;

		delete ptr;
	}
	return (0);
}