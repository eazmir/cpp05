#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        const int         grade_signed;
        const int         grade_excute;
        bool          is_signed;
    public:
        virtual void execute(Bureaucrat const &executor) const = 0;
        virtual ~AForm();
        class GradeTooHighException:public std::exception
        {
            public:
               virtual const char* what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                virtual  const char* what() const throw();
        };
        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        AForm(const std::string &name,const int grade_signed,const int grade_excute);
        void beSigned(Bureaucrat &bur);
        int get_grade_signed()const ;
        int get_grade_execute()const;
        bool get_is_signed() const;
        const std::string &get_name() const;
};

std::ostream &operator<<(std::ostream &os,const AForm &Aform);
#endif