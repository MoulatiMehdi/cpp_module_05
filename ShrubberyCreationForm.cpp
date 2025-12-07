#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cerrno>
#include <cstring>
#include <fstream>
#include <stdexcept>
#include <string>

const std::string ShrubberyCreationForm::NAME = "shrubbery creation";

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name)
    : AForm(NAME, 145, 137),
      _target(name)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other),
      _target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    _target = other._target;
    return *this;
}

void ShrubberyCreationForm::executeFormAction() const
{
    std::string   name = _target + "_shrubbery";
    std::ofstream out(name.c_str());

    if (!out.is_open())
        throw std::runtime_error(
            name + " file was not created (" + strerror(errno) + ")"
        );
    out << "      '.," << std::endl;
    out << "        'b      *" << std::endl;
    out << "         '$    #." << std::endl;
    out << "          $:   #:" << std::endl;
    out << "          *#  @):" << std::endl;
    out << "          :@,@):   ,.**:'" << std::endl;
    out << ",         :@@*: ..**'" << std::endl;
    out << " '#o.    .:(@'.@*\"'" << std::endl;
    out << "    'bq,..:,@@*'   ,*" << std::endl;
    out << "    ,p$q8,:@)'  .p*'" << std::endl;
    out << "   '    '@@Pp@@*'" << std::endl;
    out << "         Y7'.'" << std::endl;
    out << "        :@):." << std::endl;
    out << "       .:@:'." << std::endl;
    out << "     .::(@:." << std::endl;
    if (out.fail())
        throw std::runtime_error(
            name + " file is not writable (" + strerror(errno) + ")"
        );
    out.close();
}
