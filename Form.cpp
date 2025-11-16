
#include "Form.hpp"
#include <iostream>
#include <string>

Form::TooLow::GradeTooLowException()
    : std::range_error("Grade invalid : too low")
{
}

Form::TooHigh::GradeTooHighException()
    : std::range_error("Grade invalid : too high")
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _signed(false),
      _name(name),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
    throwIfInvalidGrade(_gradeToSign);
    throwIfInvalidGrade(_gradeToExecute);
}

Form::Form(const Form &other)
    : _signed(other._signed),
      _name(other._name),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute)
{
}

Form::~Form() {}

Form &Form::operator=(const Form &other)
{
    return *this;
}

const std::string &Form::getName() const
{
    return _name;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

void Form::beSigned(Bureaucrat &other)
{
    throwIfInvalidGrade(other.getGrade());
    if (other.getGrade() < _gradeToSign)
        _signed = true;
}

void Form::throwIfInvalidGrade(int grade) throw(TooLow, TooHigh)
{
    if (Grade::isGradeTooHigh(grade))
        throw TooHigh();
    if (Grade::isGradeTooLow(grade))
        throw TooLow();
}

std::ostream &operator<<(std::ostream &out, Form &other)
{
    std::cout << other.getName() << ", grade to sign " << other.getGradeToSign()
              << ", grade to execute " << other.getGradeToExecute()
              << std::endl;
    return out;
}
