#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;
class                       Form {

    public:
    
        class                   GradeTooHighException : public std::exception {
            public:
                GradeTooHighException(void);
                virtual ~GradeTooHighException(void) throw();
                GradeTooHighException(GradeTooHighException const & grade);
                GradeTooHighException &operator=(GradeTooHighException const & grade);
                virtual const char * what() const throw();
        };

        class                   GradeTooLowException : public std::exception {
            public:
                GradeTooLowException(void);
                virtual ~GradeTooLowException(void) throw();
                GradeTooLowException(GradeTooLowException const & grade);
                GradeTooLowException &operator=(GradeTooLowException const & grade);
                virtual const char * what() const throw();
        };

        class                   FormNotSigned : public std::exception {
            public:
                FormNotSigned(void);
                virtual ~FormNotSigned(void) throw();
                FormNotSigned(FormNotSigned const & form);
                FormNotSigned &operator=(FormNotSigned const & form);
                virtual const char * what() const throw();
        };

        Form(std::string name, int minSign, int minEx);
        ~Form(void) throw();
        Form(Form const & form);
        Form &operator=(Form const & form);

        std::string const   getName(void) const;
        int const           getMinSign(void) const;
        int const           getMinEx(void) const;
        bool                isSigned(void) const;
        void                beSigned(Bureaucrat & bureaucrat);
        virtual void        execute(Bureaucrat const & bureaucrat) const = 0;

    private:
        std::string const   name;
        bool                is_signed;
        int const           sign_min;
        int const           ex_min;

        Form(void);

};

std::ostream                &operator<<(std::ostream &out, Form const & bureaucrat);

#endif