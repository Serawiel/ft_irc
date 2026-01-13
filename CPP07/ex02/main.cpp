#include "Array.hpp"

int	main(void)
{
	std::cout << "=== TEST 1: Default constructor" << std::endl;
	{
		Array<int> empty;
		std::cout << "Length: " << empty.size() << std::endl;
	}

	std::cout << "\n=== TEST 2: n constructor" << std::endl;
	{
		Array<int> arr(5);
		std::cout << "Length: " << arr.size() << std::endl;

		for (unsigned int i = 0; i < arr.size(); i++)
		{
			arr[i] = i + 1;
			std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
		}
	}

	std::cout << "\n=== TEST 3: Copy constructor ===" << std::endl;
	{
		Array<int> a(3);
		a[0] = 100;
		a[1] = 200;
		a[2] = 300;

		Array<int> b(a);

		std::cout << "Original a[0] = " << a[0] << std::endl;
		std::cout << "Copy b[0] = " << b[0] << std::endl;

		b[0] = 42;

		std::cout << "After modification of b:" << std::endl;
		std::cout << "a[0] = " << a[0] << std::endl;
		std::cout << "b[0] = " << b[0] << std::endl;
	}

	std::cout << "\n=== TEST 4: = Operator ===" << std::endl;
	{
		Array<int> a(3);
		a[0] = 10;
		a[1] = 20;
		a[2] = 30;

		Array<int> b(5);
		b[0] = 1;

		std::cout << "Before affectation:" << std::endl;
		std::cout << "a.size() = " << a.size() << std::endl;
		std::cout << "b.size() = " << b.size() << std::endl;

		b = a;

		std::cout << "After b = a:" << std::endl;
		std::cout << "a.size() = " << a.size() << std::endl;
		std::cout << "b.size() = " << b.size() << std::endl;
		std::cout << "a[0] = " << a[0] << std::endl;
		std::cout << "b[0] = " << b[0] << std::endl;

		b[0] = 777;
		std::cout << "After b[0] = 777 :" << std::endl;
		std::cout << "a[0] = " << a[0] << std::endl;
		std::cout << "b[0] = " << b[0] << std::endl;
	}

	std::cout << "\n=== TEST 5: Excpetion out of range ===" << std::endl;
	{
		Array<int> arr(3);

		try
		{
			std::cout << "Try to access arr[10]..." << std::endl;
			arr[10] = 100;
		}
		catch (std::exception &e)
		{
			std::cout << "Out of range !" << std::endl;
		}
	}

	std::cout << "\n=== TEST 6: Differents types ===" << std::endl;
	{
		Array<std::string> strings(3);
		strings[0] = "Hello";
		strings[1] = "World";
		strings[2] = "42";

		std::cout << "Strings:" << std::endl;
		for (unsigned int i = 0; i < strings.size(); i++)
			std::cout << "strings[" << i << "] = " << strings[i] << std::endl;

		Array<float> floats(2);
		floats[0] = 3.14f;
		floats[1] = 2.71f;

		std::cout << "Floats:" << std::endl;
		for (unsigned int i = 0; i < floats.size(); i++)
			std::cout << "floats[" << i << "] = " << floats[i] << std::endl;
	}

	return (0);
}