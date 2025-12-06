#ifndef A_FORM_HPP
#define A_FORM_HPP

#include "Bureaucrat.hpp"
#include <stdexcept>
#include <string>

class AForm
{
  public:
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);

    virtual ~AForm();
    virtual void beSigned(Bureaucrat &other) = 0;

    bool               isSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;
    const std::string &getName() const;

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

    typedef GradeTooLowException  TooLow;
    typedef GradeTooHighException TooHigh;

  private:
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;
    const std::string _name;

    AForm      &operator=(const AForm &other);
    static void throwIfInvalidGrade(int grade) throw(TooLow, TooHigh);
};

#endif
