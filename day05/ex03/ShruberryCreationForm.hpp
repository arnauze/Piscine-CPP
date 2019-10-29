#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"

class                           Bureaucrat;
class                           ShruberryCreationForm : public Form {
    public:
        ShruberryCreationForm(void);
        ShruberryCreationForm(std::string target);
        ~ShruberryCreationForm(void);
        ShruberryCreationForm(ShruberryCreationForm const & form);
        ShruberryCreationForm   &operator=(ShruberryCreationForm const & form);

        void                    execute(Bureaucrat const & bureaucrat) const;
        void                    setTarget(std::string const & target);
        std::string             getTarget(void) const;
    
    private:
        std::string             target;
};

#endif