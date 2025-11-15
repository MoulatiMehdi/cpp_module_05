#include <stdexcept>
#include <string>

class Bureaucrat
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

    typedef GradeTooLowException  TooLow;
    typedef GradeTooHighException TooHigh;

    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &other);

    const std::string &getName() const;
    int                getGrade() const;
    void               incrementGrade();
    void               decrementGrade();

  private:
    static const int GRADE_MAX;
    static const int GRADE_MIN;

    const std::string _name;
    int               _grade;

    static void throwIfInvalidGrade(int grade) throw(TooLow, TooHigh);
    static bool isGradeTooLow(int grade);
    static bool isGradeTooHigh(int grade);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &other);
