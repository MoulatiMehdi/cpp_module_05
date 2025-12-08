#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <stdexcept>
#include <string>

class Form
{
  public:
    class GradeTooHighException : public std::out_of_range
    {
      public:
        GradeTooHighException();
    };

    class GradeTooLowException : public std::out_of_range
    {
      public:
        GradeTooLowException();
    };

    Form();
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    ~Form();
    Form &operator=(const Form &other);

    void beSigned(const Bureaucrat &other);

    bool               isSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;
    const std::string &getName() const;

  private:
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;
    const std::string _name;

    static void throwIfInvalidGrade(int grade) throw(
        GradeTooLowException, GradeTooHighException
    );
};

std::ostream &operator<<(std::ostream &out, const Form &other);
#endif
