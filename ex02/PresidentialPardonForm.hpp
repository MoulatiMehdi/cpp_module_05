#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
  private:
    std::string _target;

  public:
    static const std::string NAME;
    static AForm            *clone(const std::string &target);

    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &name);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    void executeFormAction() const;
};

#endif
