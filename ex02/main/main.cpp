#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void)
{
    {
        try
        {
            Bureaucrat manager("Manager", 145);
            Bureaucrat developer("Developer", 137);
            ShrubberyCreationForm shrubbery("office");
            manager.signForm(shrubbery);
            developer.executeForm(shrubbery);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        try
        {
            Bureaucrat manager("Manager", 45);
            Bureaucrat developer("Developer", 70);
            RobotomyRequestForm robotomy("Server");
            for (int i = 0; i < 6;i++)
            {
                developer.signForm(robotomy);
                manager.executeForm(robotomy);
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        try
        {
            Bureaucrat ceo("CEO", 1);
            Bureaucrat manager("Manager", 20);
            PresidentialPardonForm pardon("Employee");
            manager.signForm(pardon);
            ceo.executeForm(pardon);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        try
        {
            Bureaucrat intern("Intern", 150);
            Bureaucrat manager("Manager", 100);
            RobotomyRequestForm robotomy("Coffee_Machine");
            intern.signForm(robotomy);
            manager.executeForm(robotomy);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}