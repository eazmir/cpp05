#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        const int         grade_signed;
        const int         grade_excute;
        bool          is_signed;
    public:
        class GradeTooHighException:public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        Form();
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        Form(const std::string &name,const int grade_signed,const int grade_excute);
        void beSigned(Bureaucrat &bur);
        bool get_is_signed() const;
        const std::string &get_name() const;
        int get_grade_signed()const ;
        int get_grade_execute()const;
};

std::ostream &operator<<(std::ostream &os,const Form &form);
#endif