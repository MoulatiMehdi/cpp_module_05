#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>

const std::string PresidentialPardonForm::NAME = "presidential pardon";

PresidentialPardonForm::PresidentialPardonForm()
    : AForm(NAME, 25, 5),
      _target("unknown")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name)
    : AForm(NAME, 25, 5),
      _target(name)
{
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other
)
    : AForm(other),
      _target(other._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    _target = other._target;
    return *this;
}

void PresidentialPardonForm::executeFormAction() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox"
              << std::endl;
}

AForm *PresidentialPardonForm::clone(const std::string &target)
{
    return new PresidentialPardonForm(target);
}
