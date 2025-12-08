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

    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    virtual ~AForm();
    AForm &operator=(const AForm &other);

    void beSigned(const Bureaucrat &other);

    int                getGradeToSign() const;
    int                getGradeToExecute() const;
    bool               isSigned() const;
    const std::string &getName() const;

    virtual void executeFormAction() const = 0;
    void         execute(const Bureaucrat &other) const;

  private:
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;
    const std::string _name;

    static void throwIfInvalidGrade(int grade) throw(
        GradeTooLowException, GradeTooHighException
    );
};

std::ostream &operator<<(std::ostream &out, const AForm &other);
#endif
