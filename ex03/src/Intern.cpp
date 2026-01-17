#include "../include/Intern.hpp"

const char *Intern::InvalidName::what() const throw()
{
    return (RED"==Form name not recognized");
}

Intern::Intern():temp(NULL)
{}

Intern::Intern(const Intern &other)
{
    {
        (void)other; //No thing To copy !.
    }
}

Intern &Intern::operator=(const Intern &other)
{
    if (this != &other)
    {
        //No thing To Assign !.
    }
    return (*this);
}

Intern::~Intern()
{
    delete this->temp;
}

AForm *Intern::Shrubbery(std::string target)
{
    return (this->temp = new ShrubberyCreationForm(target));
}
AForm *Intern::Robotomy(std::string target)
{
    return (this->temp = new RobotomyRequestForm(target));
}
AForm *Intern::Presidential(std::string target)
{
    return (this->temp = new PresidentialPardonForm(target));
}

AForm  *Intern::makeForm(std::string name,std::string target)
{
    std::string nameForms[] = 
    {                           "Shrubbery",
                                "Robotomy Request",
                                "Presidential Pardon"
    };
    AForm *(Intern::*createForm[])(std::string) =
    {
                                &Intern::Shrubbery,
                                &Intern::Robotomy,
                                &Intern::Presidential                  
    };
    for (int index = 0; index < 3;index++)
    {
        if (name == nameForms[index])
            return (this->*createForm[index])(target);
    }
    if (true)
        throw InvalidName();
    return (NULL);
}