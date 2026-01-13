#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Too High\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Too Low\n";
}
Bureaucrat::Bureaucrat():
    name(""),
    grade(0)
{}

Bureaucrat::Bureaucrat(const Bureaucrat &other):
    name(other.name),
    grade(other.grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        //Nothing to assign
    }
    return (*this);
}

Bureaucrat::Bureaucrat(const std::string name,const int grade):
    name(name),
    grade(grade)
{
    if (this->grade <= 0)
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

void Bureaucrat::increment()
{
    this->grade++;
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decrement()
{
    this->grade--;
    if (this->grade < 0)
        throw Bureaucrat::GradeTooHighException();
}