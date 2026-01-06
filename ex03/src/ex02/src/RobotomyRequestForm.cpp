#include "../include/RobotomyRequestForm.hpp"
#include "../include/Form.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
:
    AForm(other),
    target(other.target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}
RobotomyRequestForm::RobotomyRequestForm(std::string name):AForm("RobotomyRequestForm",72,45),target(name)
{}
void RobotomyRequestForm::execute(Bureaucrat const &executer) const
{
     if (!get_is_signed())
        throw AForm::FormNotSignedException();
    if (executer.getGrade()  > get_grade_execute())
        throw AForm::GradeTooLowException();
    if (std::rand() % 2 == 0)
        std::cout <<target<<" "<<"has been robotomized successfully"<<std::endl;
    else
        std::cout << "Robotomy failed on " << target << std::endl;
}