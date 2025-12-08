#include "AForm.hpp"
#include <string>

class Intern
{
  public:
    Intern();
    Intern(const Intern &);
    ~Intern();

    Intern &operator=(const Intern &);
    AForm  *makeForm(std::string name, std::string target);
};
