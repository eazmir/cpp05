#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <iostream>

class Bureaucrat
{
    private:
        std::string name;
        int grade;
    public:
        class GradeTooHighException:public std::exception
        {
            public:
               virtual const char* what() const throw();
        };
        class GradeTooLowException:public std::exception
        {
            public:
                virtual  const char* what() const throw();
        };
        Bureaucrat(const std::string name,int grade);
        ~Bureaucrat();
        const std::string &getName()const;
        int  getGrade()const;
};

std::ostream &operator<<(std::ostream &os,const Bureaucrat &bur);
#endif