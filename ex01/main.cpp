#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    {
        Form       b("contract", 15, 17);
        Bureaucrat a("Bob", 15);

        a.signForm(b);
    }
    {
        Form       b("contract", 15, 17);
        Bureaucrat a("Bob", 19);

        a.signForm(b);
    }
    return 0;
}
