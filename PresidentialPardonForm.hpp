#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
  private:
    std::string _target;

  public:
    PresidentialPardonForm(const std::string &name);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    void executeFormAction() const;
};

#endif
