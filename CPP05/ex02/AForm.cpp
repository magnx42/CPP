#include "AForm.hpp"
#include "Bureaucrat.hpp"
AForm::AForm() : _name("Contract default name"), _signed(false), _gradeExec(70), _gradeSign(70)
{
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _gradeExec(other._gradeExec), _gradeSign(other._gradeSign)
{
	std::cout << "Default AForm copy constructor called" << std::endl;
}

AForm::AForm(std::string name, int exec, int sign) : _name(name), _signed(false), _gradeExec(exec), _gradeSign(sign)
{
	std::cout << "Default parametters AForm constructor called" << std::endl;
	if(exec < 1 || sign < 1)
		throw GradeTooHighException();
	else if(exec > 150 || sign > 150)
		throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "Default AForm copy assignation called" << std::endl;
	if(this != &other)
		this->_signed = other._signed;
	return *this;
}

AForm::~AForm()
{
	std::cout << "Default AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeExec() const
{
	return _gradeExec;
}

int AForm::getGradeSign() const
{
	return _gradeSign;
}

void AForm::beSigned(const Bureaucrat& bur)
{
	if(bur.getGrade() > _gradeSign)
		throw GradeTooLowException();
	else
		_signed = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	out << "| AForm |" << std::endl << "Name: " << AForm.getName() << std::endl << "Is signed: " << std::boolalpha << AForm.getSigned() << std::noboolalpha <<  std::endl << "Execute grade: " << AForm.getGradeExec() << std::endl << "Grade Sign: " << AForm.getGradeSign();
	return out;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}
