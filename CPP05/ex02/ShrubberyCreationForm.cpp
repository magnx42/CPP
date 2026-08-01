#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 137, 145), _target("default target")
{
    std::cout << "Default ShrubberyCreationForm constructor called" <<  std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 137, 145), _target(target)
{
    std::cout << "Default parameters ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    std::cout << "Default operator= assignation ShrubberyCreationForm called" << std::endl;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm  const & other) : AForm(other), _target(other._target)
{
    std::cout << "Default copy ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Default ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->verifgrade(executor);
    std::string outfile = this->_target + "_shrubbery";
    std::ofstream output(outfile.c_str());
    if(!output)
        throw CannotCreateFileException();
    output << "   /\\"     << std::endl
          << "  /  \\"    << std::endl
          << " /    \\"   << std::endl
          << "/______\\"  << std::endl
          << "   ||"      << std::endl
          << "   ||"      << std::endl;
    output.close();
    if(output.fail())
        throw WritingErrorException();
}

const char* ShrubberyCreationForm::CannotCreateFileException::what() const throw()
{
    return "Cannot create file.";
}

const char* ShrubberyCreationForm::WritingErrorException::what() const throw()
{
    return "Writing error";
}