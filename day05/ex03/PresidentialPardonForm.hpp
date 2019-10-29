#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"

class                           Bureaucrat;
class                           PresidentialPardonForm : public Form {
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm(PresidentialPardonForm const & form);
        PresidentialPardonForm &operator=(PresidentialPardonForm const & form);

        void                    execute(Bureaucrat const & bureaucrat) const;
        void                    setTarget(std::string const & target);
        std::string             getTarget(void) const;
    
    private:
        std::string             target;
};

#endif