#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>

const std::string RobotomyRequestForm::NAME = "robotomy request";

AForm *RobotomyRequestForm::clone(const std::string &target) 
{
    return new RobotomyRequestForm(target);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name)
    : AForm(NAME, 72, 45),
      _target(name)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other),
      _target(other._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    _target = other._target;
    return *this;
}

void RobotomyRequestForm::executeFormAction() const
{
    std::cout << "* DRILLING NOISE *" << std::endl;
    std::srand(std::time(NULL));

    if (rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully!"
                  << std::endl;
    else
        throw std::runtime_error("the robotomy of " + _target + " failed");
}

