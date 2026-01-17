#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Too High";
}

const char* Bureaucrat::GradeTooLowException::what()const throw()
{
    return "Too Low";
}

Bureaucrat::Bureaucrat():name(""),grade(0)
{
    std::cout << "Bureaucrat created and starting work" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other):
    name(other.name)
{
    this->grade = other.grade;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return (*this);
}
Bureaucrat::~Bureaucrat()
{
    std::cout <<RED<<"|-------" <<this->name << " finished his work" <<"---------|"<<RESET<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string name,int grade):name(name),grade(grade)
{
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
     std::cout <<GREEN<< "===Bureaucrat "<<this->name<<" created and starting work===" <<RESET<< std::endl;
}

const std::string &Bureaucrat::getName() const
{
    return (this->name);
}

void Bureaucrat::increment(void)
{
    if (this->grade++ > 150)
        throw Bureaucrat::GradeTooLowException();
}
void Bureaucrat::decrement(void)
{
    if (this->grade-- < 1)
        throw Bureaucrat::GradeTooHighException();
}
int Bureaucrat::getGrade()const
{
    return (this->grade);
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << "\n" << GREEN << "==form executed successfully==" << RESET << std::endl;
        std::cout << "+----------------------------------------+" << std::endl;
        std::cout << "| Name:   " << std::setw(30) << this->name << " |" << std::endl;
        std::cout << "| Grade:  " << std::setw(30) << this->grade << " |" << std::endl;
        std::cout << "+----------------------------------------+" << std::endl;
        std::cout <<form;
        std::cout << "| Execute: " << std::setw(29) << "Yes" << " |" << std::endl;
        std::cout << "+----------------------------------------+" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cout << RED << "===" << this->name << " "
                  << "couldn't execute " << form.get_name() 
                  << " because " << e.what() << "===" << RESET << std::endl;
        std::cout << "+----------------------------------------+" << std::endl;
        std::cout << "| Name:   " << std::setw(30) << this->name << " |" << std::endl;
        std::cout << "| Grade:  " << std::setw(30) << this->grade << " |" << std::endl;
        std::cout << "+----------------------------------------+" << std::endl;
        std::cout<<form;
    }
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout <<"\n"<< GREEN << "===form signed successfully===" << RESET << std::endl;
        std::cout << "+----------------------------------------+" << std::endl;
        std::cout << "| Name:   " << std::setw(30) << this->name << " |" << std::endl;
        std::cout << "| Grade:  " << std::setw(30) << this->grade << " |" << std::endl;
        std::cout << "+----------------------------------------+" << std::endl;
        std::cout << form;
    }
    catch(const std::exception& e)
    {
        std::cout <<RED<<"==="<< this->name<<" "
                  << "couldn't sign " << form.get_name() 
                  << " because " << e.what() <<"==="<<RESET<<std::endl;
        std::cout << "+----------------------------------------+" << std::endl;
        std::cout << "| Name:   " << std::setw(30) << this->name << " |" << std::endl;
        std::cout << "| Grade:  " << std::setw(30) << this->grade << " |" << std::endl;
        std::cout << "+----------------------------------------+" << std::endl;
        std::cout <<form;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur)
{
    os << "+----------------------------------------+" << std::endl;
    os << "| Name:   " << std::setw(30) << bur.getName() << " |" << std::endl;
    os << "| Grade:  " << std::setw(30) << bur.getGrade() << " |" << std::endl;
    os << "+----------------------------------------+" << std::endl;
    return os;
}
