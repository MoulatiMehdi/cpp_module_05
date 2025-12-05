
#include "Form.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

Form::TooLow::GradeTooLowException()
    : std::out_of_range("Grade invalid : too low")
{
}

Form::TooHigh::GradeTooHighException()
    : std::out_of_range("Grade invalid : too high")
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _name(name)
{
    throwIfInvalidGrade(_gradeToSign);
    throwIfInvalidGrade(_gradeToExecute);
}

Form::Form(const Form &other)
    : _signed(other._signed),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute),
      _name(other._name)
{
}

Form::~Form() {}

Form &Form::operator=(const Form &)
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

bool Form::isSigned() const
{
    return _signed;
}

void Form::beSigned(Bureaucrat &other)
{
    throwIfInvalidGrade(other.getGrade());
    if (_signed)
        throw std::logic_error("Form is signed already.");
    if (other.getGrade() > _gradeToSign)
        throw std::range_error("Grade not high enough to sign.");
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
