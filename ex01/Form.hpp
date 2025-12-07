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

    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    ~Form();

    void beSigned(Bureaucrat &other);

    bool               isSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;
    const std::string &getName() const;

  private:
    typedef GradeTooLowException  TooLow;
    typedef GradeTooHighException TooHigh;

    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;
    const std::string _name;

    Form       &operator=(const Form &other);
    static void throwIfInvalidGrade(int grade) throw(TooLow, TooHigh);
};

#endif
