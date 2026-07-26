#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <exception>
#include <string>
class Bureaucrat;

class Form { 
private:
	const std::string _name;
	bool _signed;
	const int _gradeExec;
	const int _gradeSign;
public:
	Form();
	Form(const Form& other);
	Form(std::string name, int exec, int sign);
	Form& operator=(const Form& other);
	~Form();
	std::string getName() const;
	bool getSigned() const;
	int getGradeExec() const;
	int getGradeSign() const;
	void beSigned(const Bureaucrat& bur);
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
	class GradeTooHighException : public std::exception{
	public:
		const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream &out, const Form& form);

#endif