#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
:
    AForm(other),
    target(other.target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &Other)
{
    if (this != &Other)
    {
        AForm::operator=(Other);
    }
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string name):
    AForm("PresidentialPardonForm",25,5),
    target(name)
{}

void PresidentialPardonForm::execute(Bureaucrat const &excuter) const
{
     if (!get_is_signed())
        throw AForm::FormNotSignedException();
    if (excuter.getGrade() > get_grade_execute())
        throw AForm::GradeTooLowException();
    std::cout <<target<<" "<<"has been pardoned by Zaphod Beeblebrox."<<std::endl;
}


