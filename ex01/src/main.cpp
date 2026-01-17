#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

int main(void)
{
    {
        try
        {
            Bureaucrat staff("Alex", 1);
            staff.decrement();
            staff.increment();
            Form form("Tax Form", 10, 2);
            staff.signForm(form);
            std::cout << form << std::endl; 
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat intern("Bob", 50);
            Form form("Important Document", 10, 5);
            intern.signForm(form);
            std::cout << form << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat boss("Charlie", 1);
            Form invalidForm1("Bad Form 1", 0, 50);
            std::cout << invalidForm1 << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
        
        try
        {
            Form invalidForm2("Bad Form 2", 50, 151);
            std::cout << invalidForm2 << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat manager("Diana", 5);
            Form form("Contract", 10, 8);
            std::cout <<manager;
            std::cout << form << std::endl;
            manager.signForm(form);
            std::cout << form << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat President("President", 1);
            Bureaucrat Janitor("Janitor", 150);
            Form easyForm("Easy Form", 150, 150);
            Form hardForm("Hard Form", 1, 1);
            Janitor.signForm(easyForm);
            std::cout << easyForm;
            Janitor.signForm(hardForm);
            std::cout << hardForm;
            President.signForm(hardForm);
            std::cout <<hardForm;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    return 0;
}
