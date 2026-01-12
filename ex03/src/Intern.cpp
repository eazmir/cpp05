#include "../include/Intern.hpp"

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

AForm *Intern::summonForm(std::string target,int index)
{   
    if (index == 0)
       return (this->temp = new ShrubberyCreationForm(target));
    else if (index == 1)
        return (this->temp = new RobotomyRequestForm(target));
    else if (index == 2)
        return (this->temp = new PresidentialPardonForm(target));
    return (this->temp);
}

static void error(std::string msg)
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
            return (this->summonForm(target,index));
    }
    error("Invalid Name");
    return (NULL);
}