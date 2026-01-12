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
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();
        AForm *makeForm(std::string name,std::string target);
        AForm *summonForm(std::string target,int index);
};
