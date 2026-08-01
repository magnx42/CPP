#ifndef  SHRUBBERYCREATIONFORM_HPP
#define  SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm  : public AForm
{
private:
    std::string _target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm & operator=(ShrubberyCreationForm  const & other);
    ShrubberyCreationForm(ShrubberyCreationForm const & other);
    ~ShrubberyCreationForm();
    void execute(Bureaucrat const  & executor) const;
    class CannotCreateFileException : public std::exception
    {
    public:
        const char* what() const throw();
    };
    class  WritingErrorException : public std::exception
    {
    public:
        const char* what() const throw();
    };
};

#endif