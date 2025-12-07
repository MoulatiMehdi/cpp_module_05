#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    {
        Form       b("contract", 15, 17);
        Bureaucrat a("Bob", 15);

        std::cout << a;
        std::cout << b;
        
        std::cout << "Signing Contract ==>";
        a.signForm(b);
        std::cout << b;
        
        std::cout << std::endl;
    }
    {
        Form       b("contract", 15, 17);
        Bureaucrat a("Bob", 19);

        std::cout << a;
        std::cout << b;
        
        std::cout << "Signing Contract ==>";
        a.signForm(b);
        std::cout << b;

        std::cout << std::endl;
    }
    return 0;
}
