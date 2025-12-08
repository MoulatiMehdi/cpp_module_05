#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>
#include <string>

int main()
{

    {
        Intern      guy;
        Bureaucrat  bob("Bob", 5);
        std::string names[4] = {
            "shrubbery creation",
            "robotomy request",
            "presidential pardon",
            "nonsense text"
        };

        for (int i = 0; i < 4; i++)
        {
            AForm *form;
            form = guy.makeForm(names[i], "bender");
            if (form != NULL)
            {
                bob.signForm(*form);
                bob.executeForm(*form);
            }
            std::cout << std::string(50, '-') << std::endl;
        }
    }
    return 0;
}
