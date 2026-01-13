#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
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
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        Bureaucrat(const std::string name,const int grade);
        ~Bureaucrat();
        const std::string &getName()const;
        int  getGrade()  const;
        void increment();
        void decrement();
};

std::ostream &operator<<(std::ostream &os,const Bureaucrat &bur);
#endif