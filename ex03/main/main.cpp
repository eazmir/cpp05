#include "../include/Intern.hpp"

int main(void)
{
    {
        try
        {
            AForm *rrf;
            Intern intern;
            Bureaucrat john("John", 72);
            rrf = intern.makeForm("Robotomy Reques", "Robert");
            john.signForm(*rrf);
            john.executeForm(*rrf);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        try
        {
            AForm *rrf;
            Intern intern;
            Bureaucrat maria("mark", 45);
            rrf = intern.makeForm("Shrubbery", "Emma");
            maria.signForm(*rrf);
            maria.executeForm(*rrf);
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            AForm *rrf;
            Intern intern;
            Bureaucrat david("David", 5);
            rrf = intern.makeForm("Presidential Pardon", "Lucas");
            david.signForm(*rrf);
            david.executeForm(*rrf);
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}