#include "Bureaucrat.hpp"
#include <cmath>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

void title(const std::string &label)
{
    std::cout << std::string(100, '-') << std::endl;
    std::cout << "\t" << label << std::endl;
    std::cout << std::string(100, '-') << std::endl;
}

int main(int, char *[])
{
    title("Should Work Normaly (constructors)");
    {
        try
        {
            Bureaucrat a("bob", 50);
            Bureaucrat b("ali", 80);

            std::cout << "A : " << a;
            std::cout << "B : " << b << std::endl;

            b = a;

            std::cout << "A : " << a;
            std::cout << "B : " << b;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    title("Should Throw a GradeTooHighException exception");
    try
    {
        Bureaucrat a("bob", -1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    title("Should Throw a GradeTooLowException exception");
    try
    {
        Bureaucrat a("bob", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    title("Should Work Normaly (incrementGrade /decrementGrade)");
    try
    {
        Bureaucrat a("bob", 3);

        std::cout << a;

        std::cout << "Decrementing => ";
        a.decrementGrade();
        std::cout << a;

        std::cout << "Incrementing => ";
        a.incrementGrade();
        std::cout << a;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    title("Should Throw a GradeTooHighException exception");
    try
    {
        Bureaucrat a("bob", 1);

        std::cout << a;

        a.incrementGrade();
        std::cout << a;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    title("Should Throw a GradeTooLowException exception");
    try
    {
        Bureaucrat a("bob", 150);

        std::cout << a;

        a.decrementGrade();
        std::cout << a;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
