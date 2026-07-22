#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
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
	class GradeTooLowException;
	class GradeTooHighException;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &fixed);

#endif