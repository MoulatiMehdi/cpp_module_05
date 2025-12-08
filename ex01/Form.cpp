
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

Form::GradeTooLowException::GradeTooLowException()
    : std::out_of_range("grade is too low")
{
}

Form::GradeTooHighException::GradeTooHighException()
    : std::out_of_range("grade is too high")
{
}

void Form::throwIfInvalidGrade(int grade) throw(
    GradeTooLowException, GradeTooHighException
)
{
    if (Grade::isGradeTooHigh(grade))
        throw GradeTooHighException();
    if (Grade::isGradeTooLow(grade))
        throw GradeTooLowException();
}

Form::Form()
    : _isSigned(false),
      _gradeToSign(Grade::GRADE_MIN),
      _gradeToExecute(Grade::GRADE_MIN),
      _name("permit")
{
    throwIfInvalidGrade(_gradeToSign);
    throwIfInvalidGrade(_gradeToExecute);
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
    throwIfInvalidGrade(_gradeToSign);
    throwIfInvalidGrade(_gradeToExecute);
}

Form::~Form()
{
}

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

void Form::beSigned(const Bureaucrat &other)
{
    if (other.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &other)
{
    std::cout << other.getName() << ", grade to sign " << other.getGradeToSign()
              << ", grade to execute " << other.getGradeToExecute()
              << ", signed " << std::boolalpha << other.isSigned() << std::endl;
    return out;
}
