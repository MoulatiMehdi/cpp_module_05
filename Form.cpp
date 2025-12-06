
#include "Form.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

Form::TooLow::GradeTooLowException()
    : std::out_of_range("grade is too low")
{
}

Form::TooHigh::GradeTooHighException()
    : std::out_of_range("grade is too high")
{
}

void Form::throwIfInvalidGrade(int grade) throw(TooLow, TooHigh)
{
    if (Grade::isGradeTooHigh(grade))
        throw TooHigh();
    if (Grade::isGradeTooLow(grade))
        throw TooLow();
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _name(name)
{
    throwIfInvalidGrade(_gradeToSign);
    throwIfInvalidGrade(_gradeToExecute);
}

Form::Form(const Form &other)
    : _isSigned(false),
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
    return _isSigned;
}

void Form::beSigned(Bureaucrat &other)
{
    if (other.getGrade() > _gradeToSign)
        throw TooLow();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, Form &other)
{
    std::cout << other.getName() << ", grade to sign " << other.getGradeToSign()
              << ", grade to execute " << other.getGradeToExecute()
              << std::endl;
    return out;
}
