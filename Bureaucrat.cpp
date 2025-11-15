#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

const int Bureaucrat::GRADE_MAX = 1;
const int Bureaucrat::GRADE_MIN = 150;

Bureaucrat::TooLow::GradeTooLowException()
    : std::range_error("Grade invalid : too low")
{
}

Bureaucrat::TooHigh::GradeTooHighException()
    : std::range_error("Grade invalid : too high")
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name),
      _grade(grade)
{
    throwIfInvalidGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name),
      _grade(other._grade)
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

bool Bureaucrat::isGradeTooHigh(int grade)
{
    return grade < GRADE_MAX;
}

bool Bureaucrat::isGradeTooLow(int grade)
{
    return grade > GRADE_MIN;
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
    if (isGradeTooHigh(grade))
        throw TooHigh();
    if (isGradeTooLow(grade))
        throw TooLow();
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &other)
{
    std::cout << other.getName() << ", bureaucrat grade " << other.getGrade()
              << std::endl;
    return out;
}
