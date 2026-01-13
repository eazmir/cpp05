#include "../src/ex02/include/Bureaucrat.hpp"
#include "../src/ex02/include/PresidentialPardonForm.hpp"
#include "../src/ex02/include/RobotomyRequestForm.hpp"
#include "../src/ex02/include/ShrubberyCreationForm.hpp"
#include "../src/ex02/include/Form.hpp"

class Intern
{
    private:
        AForm *temp;
    public:
        class InvalidName: public std::exception
        {
            virtual const char *what() const throw();
        };
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();
        AForm *makeForm(std::string name,std::string target);
        AForm *createForm(std::string target,int index);
};
