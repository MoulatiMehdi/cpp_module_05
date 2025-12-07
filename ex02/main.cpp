#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

void title(const std::string &label)
{

    std::cout << std::string(75, '*') << std::endl;
    std::cout << "*\t\t" << label << std::endl;
    std::cout << std::string(75, '*') << std::endl << std::endl;
}

int main()
{
    {
        title("ShrubberyCreationForm");
        Bureaucrat peaple[3] = {
            Bureaucrat("Bob", 146),
            Bureaucrat("Bob", 145),
            Bureaucrat("Bob", 137)
        };

        for (int i = 0; i < 3; i++)
        {
            ShrubberyCreationForm form("home");
            peaple[i].signForm(form);
            peaple[i].executeForm(form);
            std::cout << std::string(75, '-') << std::endl;
        }
    }
    std::cout << std::endl;
    {
        title("RobotomyRequestForm");
        Bureaucrat peaple[3] = {
            Bureaucrat("Bob", 73), Bureaucrat("Bob", 72), Bureaucrat("Bob", 45)
        };

        for (int i = 0; i < 3; i++)
        {
            RobotomyRequestForm form("home");
            peaple[i].signForm(form);
            peaple[i].executeForm(form);
            std::cout << std::string(75, '-') << std::endl;
        }
    }
    std::cout << std::endl;
    {
        title("PresidentialPardonForm");
        Bureaucrat peaple[3] = {
            Bureaucrat("Bob", 26), Bureaucrat("Bob", 25), Bureaucrat("Bob", 5)
        };

        for (int i = 0; i < 3; i++)
        {
            PresidentialPardonForm form("home");
            peaple[i].signForm(form);
            peaple[i].executeForm(form);
            std::cout << std::string(75, '-') << std::endl;
        }
    }

    return 0;
}
