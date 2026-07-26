#include "Form.hpp"
#include "Bureaucrat.hpp"
Form::Form() : _name("Contractpipicaca"), _signed(false), _gradeExec(70), _gradeSign(70)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _gradeExec(other._gradeExec), _gradeSign(other._gradeSign)
{
	std::cout << "Default Form copy constructor called" << std::endl;
}

Form::Form(std::string name, int exec, int sign) : _name(name), _signed(false), _gradeExec(exec), _gradeSign(sign)
{
	std::cout << "Default parametters Form constructor called" << std::endl;
	if(exec < 1 || sign < 1)
		throw GradeTooHighException();
	else if(exec > 150 || sign > 150)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Default Form copy assignation called" << std::endl;
	if(this != &other)
		this->_signed = other._signed;
	return *this;
}

Form::~Form()
{
	std::cout << "Default Form destructor called" << std::endl;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeExec() const
{
	return _gradeExec;
}

int Form::getGradeSign() const
{
	return _gradeSign;
}

void Form::beSigned(const Bureaucrat& bur)
{
	if(bur.getGrade() > _gradeSign)
		throw GradeTooLowException();
	else
		_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << "| Form |" << std::endl << "Name: " << form.getName() << std::endl << "Is signed: " << std::boolalpha << form.getSigned() << std::noboolalpha <<  std::endl << "Execute grade: " << form.getGradeExec() << std::endl << "Grade Sign: " << form.getGradeSign();
	return out;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}
