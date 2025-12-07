#ifndef A_FORM_HPP
#define A_FORM_HPP

#include "Bureaucrat.hpp"
#include <stdexcept>
#include <string>

class AForm
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

    typedef GradeTooLowException  TooLow;
    typedef GradeTooHighException TooHigh;

    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);

    virtual ~AForm();
    virtual void   executeFormAction() const              = 0;

    void               execute(const Bureaucrat &other) const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;
    bool               isSigned() const;
    const std::string &getName() const;

    void beSigned(Bureaucrat &other);

  private:
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;
    const std::string _name;

    AForm      &operator=(const AForm &other);
    static void throwIfInvalidGrade(int grade) throw(TooLow, TooHigh);
};

#endif
