#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

AForm::GradeTooLowException::GradeTooLowException()
    : std::out_of_range("grade is too low")
{
}

AForm::GradeTooHighException::GradeTooHighException()
    : std::out_of_range("grade is too high")
{
}

void AForm::throwIfInvalidGrade(int grade) throw(
    GradeTooLowException, GradeTooHighException
)
{
    if (Grade::isGradeTooHigh(grade))
        throw GradeTooHighException();
    if (Grade::isGradeTooLow(grade))
        throw GradeTooLowException();
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _name(name)
{
    throwIfInvalidGrade(_gradeToSign);
    throwIfInvalidGrade(_gradeToExecute);
}

AForm::AForm(const AForm &other)
    : _isSigned(false),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute),
      _name(other._name)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &)
{
    return *this;
}

const std::string &AForm::getName() const
{
    return _name;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

bool AForm::isSigned() const
{
    return _isSigned;
}

void AForm::beSigned(const Bureaucrat &other)
{
    if (other.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &other)
{
    std::cout << other.getName() << ", grade to sign " << other.getGradeToSign()
              << ", grade to execute " << other.getGradeToExecute()
              << ", signed " << std::boolalpha << other.isSigned() << std::endl;
    return out;
}

void AForm::execute(const Bureaucrat &other) const
{
    if (!_isSigned)
        throw std::logic_error("it is not signed");
    if (other.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    executeFormAction();
}

void AForm::executeFormAction() const
{
    std::cout << "Default Form Action is called" << std::endl;
}
