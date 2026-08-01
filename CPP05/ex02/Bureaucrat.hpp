#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include <string>
class AForm;

class Bureaucrat {
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	Bureaucrat(std::string name, int grade);
	std::string getName() const;
	int getGrade() const; 
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm& form);
	void executeForm(AForm const & form) const;
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &bur);

#endif