#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm:public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();
        RobotomyRequestForm(std::string name);
        void execute(Bureaucrat const &executer)const;
};
#endif