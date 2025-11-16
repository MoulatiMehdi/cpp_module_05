#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

const int Grade::GRADE_MAX = 1;
const int Grade::GRADE_MIN = 150;

bool Grade::isGradeTooHigh(int grade)
{
    return grade < GRADE_MAX;
}

bool Grade::isGradeTooLow(int grade)
{
    return grade > GRADE_MIN;
}

Bureaucrat::TooLow::GradeTooLowException()
    : std::out_of_range("Grade invalid : too low")
{
}

Bureaucrat::TooHigh::GradeTooHighException()
    : std::out_of_range("Grade invalid : too high")
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _grade(grade),
      _name(name)
{
    throwIfInvalidGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _grade(other._grade),
      _name(other._name)
{
    throwIfInvalidGrade(_grade);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this == &other)
        return *this;
    _grade = other._grade;
    return *this;
}

const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    throwIfInvalidGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    throwIfInvalidGrade(_grade + 1);
    _grade++;
}

void Bureaucrat::throwIfInvalidGrade(int grade) throw(TooLow, TooHigh)
{
    if (Grade::isGradeTooHigh(grade))
        throw TooHigh();
    if (Grade::isGradeTooLow(grade))
        throw TooLow();
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &other)
{
    std::cout << other.getName() << ", bureaucrat grade " << other.getGrade()
              << std::endl;
    return out;
}
