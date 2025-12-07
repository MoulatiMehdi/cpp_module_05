#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

AForm::TooLow::GradeTooLowException() : std::out_of_range("grade is too low") {}

AForm::TooHigh::GradeTooHighException() : std::out_of_range("grade is too high")
{
}

void AForm::throwIfInvalidGrade(int grade) throw(TooLow, TooHigh)
{
    if (Grade::isGradeTooHigh(grade))
        throw TooHigh();
    if (Grade::isGradeTooLow(grade))
        throw TooLow();
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

void AForm::execute(const Bureaucrat &other) const
{
    if (other.getGrade() > _gradeToExecute)
        throw TooLow();
    other.executeForm(*this);
}

void AForm::executeFormAction() const
{
    std::cout << "Default Form Action is called" << std::endl;
}

AForm::~AForm() {}

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

void AForm::beSigned(Bureaucrat &other)
{
    if (other.getGrade() > _gradeToSign)
        throw TooLow();
    _isSigned = true;
}

AForm &AForm::operator=(const AForm &)
{
    return *this;
}

std::ostream &operator<<(std::ostream &out, AForm &other)
{
    std::cout << other.getName() << ", grade to sign " << other.getGradeToSign()
              << ", grade to execute " << other.getGradeToExecute()
              << std::endl;
    return out;
}
