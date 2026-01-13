#include "Serializer.hpp"

int main()
{
	Data data;
	data.number = 42;
	data.text = "Hello 42!";
	
	Data* ptr = &data;

	std::cout << "=== Before serialization ===" << std::endl;
	std::cout << "Ptr: " << ptr << std::endl;
	std::cout << "Data: number= " << ptr->number << ", text= " << ptr->text << std::endl;
	
	std::cout << "\n=== Serialization ===" << std::endl;
	uintptr_t raw = Serializer::serialize(ptr);
	std::cout << "Uintptr_t: " << raw << std::endl;
	
	std::cout << "\n=== Deserialization ===" << std::endl;
	Data* result = Serializer::deserialize(raw);
	std::cout << "Ptr: " << result << std::endl;
	std::cout << "Data: number= " << result->number << ", text= " << result->text << std::endl;
	
	std::cout << "\n=== Verification ===" << std::endl;
	std::cout << "Identical ? " << (ptr == result ? "YES" : "NO") << std::endl;
	
	return (0);
}