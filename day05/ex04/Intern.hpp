#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShruberryCreationForm.hpp"

class                       Form;
class                       Intern {
    public:
        Form                *makeForm(std::string type, std::string target);
        Intern(void);
        ~Intern(void);
        Intern(Intern const & intern);
        Intern              operator=(Intern const & intern);
};

#endif