#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
:   
    AForm(other),
    target(other.target)
{}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
:
    AForm("Shrubbery",145,137),
    target(name)
{}
void ShrubberyCreationForm::createTree(std::ofstream &file) const
{
    std::string tree[11];
    tree[0]  = "        1337   1337";
    tree[1]  = "    C8O8O8Q8PoOb o8oo";
    tree[2]  = "  dOB69QO8PdUOpugoO9bD";
    tree[3]  = " CgggbU8OU qOp qOdoUOdcb";
    tree[4]  = "    6OuU  /p u gcoUodpP";
    tree[5]  = "      \\\\//  /douUP";
    tree[6]  = "        \\\\////";
    tree[7]  = "         |||/\\";
    tree[8]  = "         |||\\/";
    tree[9]  = "         |||||";
    tree[10] = "   .....//||||\\....";
    for (int i = 0; i < 11;i++)
    {
        file << tree[i]<<RESET<<std::endl;
    }
}

void ShrubberyCreationForm::execute(Bureaucrat const &executer) const
{
    if (!get_is_signed())
        throw AForm::FormNotSignedException();
    if (executer.getGrade() > get_grade_execute())
        throw AForm::GradeTooLowException();
    std::string name = target + "_shrubbery";
    std::ofstream file(name.c_str());
    if (!file.is_open())
    {
        std::cout <<"Error opening file"<<std::endl;
        return;
    }
    this->createTree(file);
}
