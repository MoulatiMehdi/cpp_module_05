#include "Bureaucrat.hpp"
#include "AForm.hpp"
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

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::out_of_range("grade is too low")
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
    : std::out_of_range("grade is too high")
{
}

Bureaucrat::Bureaucrat() : _grade(Grade::GRADE_MIN), _name("unknown_bureaucrat")
{
    throwIfInvalidGrade(_grade);
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

Bureaucrat::~Bureaucrat()
{
}

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

void Bureaucrat::throwIfInvalidGrade(int grade) throw(
    GradeTooLowException, GradeTooHighException
)
{
    if (Grade::isGradeTooHigh(grade))
        throw GradeTooHighException();
    if (Grade::isGradeTooLow(grade))
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other)
{
    std::cout << other.getName() << ", bureaucrat grade " << other.getGrade()
              << std::endl;
    return out;
}

void Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because "
                  << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
