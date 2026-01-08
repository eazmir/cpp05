#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <iostream>
#include <iomanip>

#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        class GradeTooHighException:public std::exception
        {
            public:
                virtual    const char* what() const throw();
        };
        class GradeTooLowException:public std::exception
        {
            public:
                virtual  const char* what() const throw();
        };
        Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &other);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat(const std::string name,int grade);
        ~Bureaucrat();
        const std::string &getName()const;
        int  getGrade()const;
        void increment();
        void decrement(void);
        void signForm(Form &form);

       
};

std::ostream &operator<<(std::ostream &os,const Bureaucrat &bur);
#endif 