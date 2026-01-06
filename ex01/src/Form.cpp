#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Too High");
}
const char* Form::GradeTooLowException::what() const throw()
{
    return ("Too Low");
}
Form::Form():name("default"),grade_signed(0),grade_excute(0),is_signed(false)
{}

Form::Form(const Form &other):
    name(other.name),
    grade_signed(other.grade_signed),
    grade_excute(other.grade_excute),
    is_signed(other.is_signed)
{}
Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return (*this);
}

Form::~Form()
{
    std::cout <<"|-----------[End of the form]----------|"<<std::endl;
}

Form::Form(const std::string &name,const int grade_signed,const int grade_excute):
    name(name),
    grade_signed(grade_signed),
    grade_excute(grade_excute),
    is_signed(false)
{
    if (this->grade_signed < 1)
        throw   Form::GradeTooHighException();
    if (this->grade_signed > 150)
        throw Form::GradeTooHighException();
    if (this->grade_excute < 1)
        throw Form::GradeTooHighException();
    if (this->grade_excute > 150)
        throw Form::GradeTooLowException();
}
void Form::beSigned(Bureaucrat &bur)
{
    if (bur.getGrade() <= this->grade_signed)
        this->is_signed = true;
    else
        throw Form::GradeTooHighException();
}
const std::string &Form::get_name() const
{
    return (this->name);
}

int Form::get_grade_execute() const
{
    return (this->grade_excute);
}

int Form::get_grade_signed() const
{
    return (this->grade_signed);
}
bool Form::get_is_signed() const
{
    return (this->is_signed);
}

std::ostream &operator<<(std::ostream &os,const Form &form)
{
    if (form.get_is_signed() == false)
    {
        os << "+--------------------------------+" << std::endl;
        os << "| Name:          " << std::setw(15)
        << form.get_name() << " |" << std::endl;
        os << "| Grade signed:  " << std::setw(15)
        << form.get_grade_signed() << " |" << std::endl;
        os << "| Grade execute: " << std::setw(15)
        << form.get_grade_execute() << " |" << std::endl;
        os << "| Signed:        " << std::setw(15)
        << (form.get_is_signed() ? "Yes" : "No") << " |" << std::endl;
        os << "+--------------------------------+" << std::endl;
    }
    else
    {
        os << "| Name:          " << std::setw(15)
        << form.get_name() << " |" << std::endl;
        os << "| Grade signed:  " << std::setw(15)
        << form.get_grade_signed() << " |" << std::endl;
        os << "| Grade execute: " << std::setw(15)
        << form.get_grade_execute() << " |" << std::endl;
        os << "| Signed:        " << std::setw(15)
        << (form.get_is_signed() ? "Yes" : "No") << " |" << std::endl;
        os << "+--------------------------------+"<<std::endl;
    }
    return os;
}
