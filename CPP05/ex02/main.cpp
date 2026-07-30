#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	std::cout << std::endl<< "=== work Form ===" << std::endl;
	try
	{
		Bureaucrat thomas("Thomas", 101);
		Form form("contract", 100, 100);

		std::cout << "Before signed: " << std::boolalpha << form.getSigned() << std::noboolalpha << std::endl;
		std::cout << "Bureaucrat grade: " << thomas.getGrade() << std::endl; 
		thomas.signForm(form);
		thomas.incrementGrade();
		thomas.signForm(form);
		std::cout << "After signed: " << std::boolalpha << form.getSigned() << std::noboolalpha << std::endl;
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl<< "=== dont work Form low ===" << std::endl;
	try
	{
		Bureaucrat thomas("Thomas", 101);
		Form form("contract", 155, 100);

		std::cout << "Before signed: " << std::boolalpha << form.getSigned() << std::noboolalpha << std::endl;
		std::cout << "Bureaucrat grade: " << thomas.getGrade() << std::endl; 
		thomas.signForm(form);
		thomas.incrementGrade();
		thomas.signForm(form);
		std::cout << "After signed: " << std::boolalpha << form.getSigned() << std::noboolalpha << std::endl;
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl<< "=== dont work Form high ===" << std::endl;
	try
	{
		Bureaucrat thomas("Thomas", 101);
		Form form("contract", 0, 100);

		std::cout << "Before signed: " << std::boolalpha << form.getSigned() << std::noboolalpha << std::endl;
		std::cout << "Bureaucrat grade: " << thomas.getGrade() << std::endl; 
		thomas.signForm(form);
		thomas.incrementGrade();
		thomas.signForm(form);
		std::cout << "After signed: " << std::boolalpha << form.getSigned() << std::noboolalpha << std::endl;
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Canonical test ===" << std::endl;

	Bureaucrat a;
	Bureaucrat b(a);
	Bureaucrat c;
	c = a;
	Form d;
	Form e(d);
	Form f;
	f = d;
}