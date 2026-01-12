#include "../include/Intern.hpp"

int main(void)
{
    {
        try
        {
            AForm *rrf;
            Intern *intern = new Intern();
            Bureaucrat john("John", 72);
            rrf = intern->makeForm("Robotomy Request", "Robert");
            john.signForm(*rrf);
            john.executeForm(*rrf);
            delete intern;
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
            Intern *intern = new Intern();
            Bureaucrat maria("mark", 45);
            rrf = intern->makeForm("Shrubbery", "Emma");
            maria.signForm(*rrf);
            maria.executeForm(*rrf);
            delete intern;
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
            Intern *intern = new Intern();
            Bureaucrat david("David", 5);
            rrf = intern->makeForm("Presidential Pardon", "Lucas");
            david.signForm(*rrf);
            david.executeForm(*rrf);
            delete intern;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}