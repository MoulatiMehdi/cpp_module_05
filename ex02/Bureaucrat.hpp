#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>

class AForm;

class Grade
{
  public:
    static const int GRADE_MAX;
    static const int GRADE_MIN;

    static bool isGradeTooLow(int grade);
    static bool isGradeTooHigh(int grade);
};

class Bureaucrat
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

    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &other);

    void signForm(AForm &form) const;

    const std::string &getName() const;
    int                getGrade() const;
    void               executeForm(const AForm &form) const;

    void incrementGrade();
    void decrementGrade();

  private:
    int               _grade;
    const std::string _name;

    static void throwIfInvalidGrade(int grade) throw(
        GradeTooLowException, GradeTooHighException
    );
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);

#endif
