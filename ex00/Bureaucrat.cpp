#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Too High\n";
}

const char* Bureaucrat::GradeTooLowException::what()const throw()
{
    return "Too Low\n";
}

Bureaucrat::Bureaucrat(const std::string name,int grade)
{
    this->name = name;
    this->grade = grade;
    if (this->grade < 0)
        throw Bureaucrat::GradeTooHighException();
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

const std::string &Bureaucrat::getName() const 
{
    return (this->name);
}

int Bureaucrat::getGrade()const
{
    return (this->grade);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur)
{
    os << bur.getName() << ", bureaucrat grade " << bur.getGrade();
    return os;
}
Bureaucrat::~Bureaucrat()
{
    std::cout<<"|--------------The end---------------|"<<std::endl;
}
