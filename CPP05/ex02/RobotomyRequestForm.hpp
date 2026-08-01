#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm  : public AForm{
private:
    std::string _target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm & operator=(RobotomyRequestForm  const & other);
    RobotomyRequestForm(RobotomyRequestForm const & other);
    ~RobotomyRequestForm();
    void execute(Bureaucrat const  & executor) const;
};

#endif