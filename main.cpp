#include "parsing.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "Error : need config file" << RESET << std::endl;
		exit(1);
	}
	try
	{
		Parsing		par(argv[1]);
	}
	catch (const std::string& e)
	{
		std::cout << RED << "Error : " << e << RESET << std::endl;
	}
	std::cout << GREEN << "Parsing Good" << std::endl;
}
