#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
  private:
    std::string _target;

  public:
    static const std::string NAME;
    static AForm            *clone(const std::string &target);

    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &name);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    void executeFormAction() const;
};

#endif
