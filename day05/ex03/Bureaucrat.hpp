#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class                       Form;
class                       Bureaucrat {
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

        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat(void) throw();
        Bureaucrat(Bureaucrat const & bureaucrat);
        Bureaucrat &operator=(Bureaucrat const & bureaucrat);

        std::string         getName(void) const;
        int                 getGrade(void) const;
        void                setGrade(int grade);
        void                incrementGrade(void);
        void                decrementGrade(void);
        void                signForm(Form & form);
        bool                executeForm(Form & form);

    private:
        std::string const   name;
        int                 grade;

};

std::ostream                &operator<<(std::ostream &out, Bureaucrat const & bureaucrat);

#endif