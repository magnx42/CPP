#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 5, 25), _target("default target")
{
    std::cout << "Default PresidentialPardonForm constructor called" <<  std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 5, 25), _target(target)
{
    std::cout << "Default parameters PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    std::cout << "Default operator= assignation PresidentialPardonForm called" << std::endl;
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm  const & other) : AForm(other), _target(other._target)
{
    std::cout << "Default copy PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Default PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    this->verifgrade(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}