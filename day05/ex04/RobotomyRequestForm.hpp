#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"

class                           Bureaucrat;
class                           RobotomyRequestForm : public Form {
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm(RobotomyRequestForm const & form);
        RobotomyRequestForm &operator=(RobotomyRequestForm const & form);

        void                    execute(Bureaucrat const & bureaucrat) const;
        void                    setTarget(std::string const & target);
        std::string             getTarget(void) const;
    
    private:
        std::string             target;
};

#endif