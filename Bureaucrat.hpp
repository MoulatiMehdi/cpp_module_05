#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>

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

    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &other);

    const std::string &getName() const;
    int                getGrade() const;

    void incrementGrade();
    void decrementGrade();

  private:
    typedef GradeTooLowException  TooLow;
    typedef GradeTooHighException TooHigh;

    int               _grade;
    const std::string _name;

    static void throwIfInvalidGrade(int grade) throw(TooLow, TooHigh);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &other);

#endif
