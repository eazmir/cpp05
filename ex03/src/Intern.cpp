#include "../include/Intern.hpp"

Intern::Intern()
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
{}

AForm *Intern::vu(std::string target,int index)
{   
    if (index == 0)
       return new ShrubberyCreationForm(target);
    else if (index == 1)
        return new RobotomyRequestForm(target);
    else if (index == 2)
        return new PresidentialPardonForm(target);
    return (NULL);
}

static void erryes(std::string msg)
{
    std::cout<<RED<<msg<<RESET<<std::endl;
    exit(0);
}

AForm  *Intern::makeForm(std::string name,std::string target)
{
    std::string nameForms[] = {
                                "Shrubbery",
                                "Robotomy Request",
                                "Presidential Pardon"
                            };
    for (int index = 0; index < 3;index++)
    {
        if (name == nameForms[index])
            return (this->vu(target,index));
    }
    erryes("Invalid Name");
    return (NULL);
}