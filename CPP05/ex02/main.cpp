#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));
	std::cout << "=== Work ===" << std::endl;

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

	//	-----------------------------------------------------
	// | AForm is now an abstract class, we cant declare it. |
	//  -----------------------------------------------------

	// std::cout << std::endl<< "=== work AForm ===" << std::endl;
	// try
	// {
	// 	Bureaucrat thomas("Thomas", 101);
	// 	AForm form("contract", 100, 100);

	// 	std::cout << "Before signed: " << std::boolalpha << form.getSigned() << std::noboolalpha << std::endl;
	// 	std::cout << "Bureaucrat grade: " << thomas.getGrade() << std::endl; 
	// 	thomas.signForm(form);
	// 	thomas.incrementGrade();
	// 	thomas.signForm(form);
	// 	std::cout << "After signed: " << std::boolalpha << form.getSigned() << std::noboolalpha << std::endl;
	// 	std::cout << form << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	
	// std::cout << std::endl<< "=== dont work AForm low ===" << std::endl;
	// try
	// {
	// 	Bureaucrat thomas("Thomas", 101);
	// 	AForm form("contract", 155, 100);

	// 	std::cout << "Before signed: " << std::boolalpha << form.getSigned() << std::noboolalpha << std::endl;
	// 	std::cout << "Bureaucrat grade: " << thomas.getGrade() << std::endl; 
	// 	thomas.signForm(form);
	// 	thomas.incrementGrade();
	// 	thomas.signForm(form);
	// 	std::cout << "After signed: " << std::boolalpha << form.getSigned() << std::noboolalpha << std::endl;
	// 	std::cout << form << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// std::cout << std::endl<< "=== dont work AForm high ===" << std::endl;
	// try
	// {
	// 	Bureaucrat thomas("Thomas", 101);
	// 	AForm form("contract", 0, 100);

	// 	std::cout << "Before signed: " << std::boolalpha << form.getSigned() << std::noboolalpha << std::endl;
	// 	std::cout << "Bureaucrat grade: " << thomas.getGrade() << std::endl; 
	// 	thomas.signForm(form);
	// 	thomas.incrementGrade();
	// 	thomas.signForm(form);
	// 	std::cout << "After signed: " << std::boolalpha << form.getSigned() << std::noboolalpha << std::endl;
	// 	std::cout << form << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	std::cout << std::endl << "=== Presidential pardon Form not signed ===" << std::endl;
	try
	{
		Bureaucrat bur("samuel", 2);
		PresidentialPardonForm pform("Pablo");
		bur.executeForm(pform);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Must be able to sign but not execute ===" << std::endl;
	try
	{
		Bureaucrat bur("Romain", 20); // sign -> 25 | exec -> 5
		PresidentialPardonForm pform("David");
		bur.signForm(pform);
		bur.executeForm(pform);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "=== Presidential pardon Form signed ===" << std::endl;
	try
	{
		Bureaucrat bur("Samuel", 2);
		PresidentialPardonForm pres("Pablo");
		bur.signForm(pres);
		bur.executeForm(pres);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Robotomy Request Form ===" << std::endl;
	try
	{
		Bureaucrat bur("Thomas", 2);
		RobotomyRequestForm robot("Clement");
		bur.signForm(robot);
		for(int i = 0;i<10;i++)
			bur.executeForm(robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "=== Shrubbery Creation Form ===" << std::endl;
	try
	{
		Bureaucrat bur("Jean", 2);
		ShrubberyCreationForm shrub("Julien");
		bur.signForm(shrub);
		bur.executeForm(shrub);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
	


	 std::cout << std::endl << "=== Canonical test Bureaucrat ===" << std::endl;

      Bureaucrat a;
      Bureaucrat b(a);
      Bureaucrat c;
      c = a;

      //      -----------------------------------------------------
      // | AForm is now an abstract class, we cant declare it. |
      //  -----------------------------------------------------
      // AForm d;
      // AForm e(d);
      // AForm f;
      // f = d;

      std::cout << std::endl << "=== Canonical test concrete forms ===" << std::endl;
      try
      {
              Bureaucrat boss("Boss", 1);

              PresidentialPardonForm original("Arthur");
              boss.signForm(original);

              // Copy constructor: _signed and _target must follow.
              std::cout << std::endl << "copy constructor" << std::endl;
              PresidentialPardonForm copy(original);
              std::cout << copy << std::endl;
              boss.executeForm(copy);

              // operator=: "default target" must be overwritten by "Arthur".
              std::cout << std::endl << "operator=" << std::endl;
              PresidentialPardonForm assigned;
              std::cout << assigned << std::endl;
              assigned = original;
              std::cout << assigned << std::endl;
              boss.executeForm(assigned);

              // Self assignation must not break anything.
              std::cout << std::endl << "self assignation" << std::endl;
              PresidentialPardonForm & ref = assigned;
              assigned = ref;
              std::cout << assigned << std::endl;
      }
      catch (const std::exception & e)
      {
              std::cerr << e.what() << std::endl;
      }
}