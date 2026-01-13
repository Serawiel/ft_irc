const char *NotFoundException::what() const throw()
{
	return "Element not found in container";
}