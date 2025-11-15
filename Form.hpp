#include "Bureaucrat.hpp"
#include <stdexcept>
#include <string>

class Form
{
  public:
    class GradeTooHighException : public std::range_error
    {
      public:
        GradeTooHighException();
    };

    class GradeTooLowException : public std::range_error
    {
      public:
        GradeTooLowException();
    };

    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    ~Form();

    bool beSigned(Bureaucrat &other);

    const std::string &getName() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;

  private:
    typedef GradeTooLowException  TooLow;
    typedef GradeTooHighException TooHigh;

    static const int GRADE_MAX;
    static const int GRADE_MIN;

    bool              _signed;
    const std::string _name;
    const int         _gradeToSign;
    const int         _gradeToExecute;

    Form       &operator=(const Form &other);
    static void throwIfInvalidGrade(int grade) throw(TooLow, TooHigh);
    static bool isGradeTooLow(int grade);
    static bool isGradeTooHigh(int grade);
};
