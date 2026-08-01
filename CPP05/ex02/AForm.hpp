#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class AForm { 
protected:
	const std::string _name;
	bool _signed;
	const int _gradeExec;
	const int _gradeSign;
	void verifgrade(Bureaucrat const & bur) const;
public:
	AForm();
	AForm(const AForm& other);
	AForm(std::string name, int exec, int sign);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
	std::string getName() const;
	bool getSigned() const;
	int getGradeExec() const;
	int getGradeSign() const;
	void beSigned(const Bureaucrat& bur);
	virtual void execute(Bureaucrat const & executor) const = 0;
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
	class GradeTooHighException : public std::exception{
	public:
		const char* what() const throw();
	};
	class FormNotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const AForm& AForm);

#endif