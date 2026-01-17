#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Too High");
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Too Low");
}
const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Not Signed");
}
AForm::AForm():name(""),grade_signed(0),grade_excute(0),is_signed(false)
{}

AForm::AForm(const AForm &other):
    name(other.name),
    grade_signed(other.grade_signed),
    grade_excute(other.grade_excute),
    is_signed(other.is_signed)
{}
AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return (*this);
}

AForm::~AForm()
{
    std::cout <<"|-----------[End of the Aform]----------|"<<std::endl;
}

AForm::AForm(const std::string &name,const int grade_signed,const int grade_excute):
    name(name),
    grade_signed(grade_signed),
    grade_excute(grade_excute),
    is_signed(false)
{
    if (this->grade_signed < 1)
        throw   AForm::GradeTooHighException();
    if (this->grade_signed > 150)
        throw AForm::GradeTooLowException();
    if (this->grade_excute < 1)
        throw AForm::GradeTooHighException();
    if (this->grade_excute > 150)
        throw AForm::GradeTooLowException();
}
void AForm::beSigned(Bureaucrat &bur)
{
    if (bur.getGrade() <= this->grade_signed)
        this->is_signed = true;
    else
        throw AForm::GradeTooLowException();
}
const std::string &AForm::get_name() const
{
    return (this->name);
}

int AForm::get_grade_execute() const
{
    return (this->grade_excute);
}

int AForm::get_grade_signed() const
{
    return (this->grade_signed);
}
bool AForm::get_is_signed() const
{
    return (this->is_signed);
}

std::ostream &operator<<(std::ostream &os, const AForm &Aform)
{
    os << "+----------------------------------------+" << std::endl;
    os << "| Name:           " << std::setw(22) << Aform.get_name() << " |" << std::endl;
    os << "| Grade signed:   " << std::setw(22) << Aform.get_grade_signed() << " |" << std::endl;
    os << "| Grade execute:  " << std::setw(22) << Aform.get_grade_execute() << " |" << std::endl;
    os << "| Signed:         " << std::setw(22) << (Aform.get_is_signed() ? "Yes" : "No") << " |" << std::endl;
    os << "+----------------------------------------+" << std::endl;
    return os;
}