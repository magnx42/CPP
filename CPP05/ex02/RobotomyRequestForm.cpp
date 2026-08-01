#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 45, 72), _target("default target")
{
    std::cout << "Default RobotomyRequestForm constructor called" <<  std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form",45, 72), _target(target)
{
    std::cout << "Default parameters RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    std::cout << "Default operator= assignation RobotomyRequestForm called" << std::endl;
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm  const & other) : AForm(other), _target(other._target)
{
    std::cout << "Default copy RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Default RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    this->verifgrade(executor);
    std::cout << "* BZZZZZ DRRRRRRR VRRRRRR *" << std::endl;
    if(rand() % 2 == 0)
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << _target << " has not been robotomized" << std::endl;
}