#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &) {}

Intern &Intern::operator=(const Intern &)
{
    return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string names[3] = {
        ShrubberyCreationForm::NAME,
        RobotomyRequestForm::NAME,
        PresidentialPardonForm::NAME,
    };
    AForm *(*funcs[3])(const std::string &) = {
        ShrubberyCreationForm::clone,
        RobotomyRequestForm::clone,
        PresidentialPardonForm::clone,
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == names[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return funcs[i](target);
        }
    }
    std::cout << "Intern didnt found form with the name " << name << std::endl;
    return NULL;
}
