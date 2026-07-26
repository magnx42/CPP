#include "Bureaucrat.hpp"

int main()
{
	std::cout << std::endl << "=== Work ===" << std::endl;

	try
	{
		Bureaucrat thomas;
		std::cout << thomas.getGrade() << std::endl;
		thomas.incrementGrade();
		std::cout << thomas.getGrade() << std::endl;
		thomas.decrementGrade();
		std::cout << thomas.getGrade() << std::endl;
		std::cout << thomas << std::endl;
		thomas.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Not work low ===" << std::endl;

	try
	{
		Bureaucrat thomas("thomas", 155);
		std::cout << thomas.getGrade() << std::endl;
		thomas.incrementGrade();
		std::cout << thomas.getGrade() << std::endl;
		thomas.decrementGrade();
		std::cout << thomas.getGrade() << std::endl;
		thomas.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

		std::cout << std::endl << "=== Not work high ===" << std::endl;

	try
	{
		Bureaucrat thomas("thomas", 0);
		std::cout << thomas.getGrade() << std::endl;
		thomas.incrementGrade();
		std::cout << thomas.getGrade() << std::endl;
		thomas.decrementGrade();
		std::cout << thomas.getGrade() << std::endl;
		thomas.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Canonical test ===" << std::endl;

	Bureaucrat a;
	Bureaucrat b(a);
	Bureaucrat c;
	c = a;
}