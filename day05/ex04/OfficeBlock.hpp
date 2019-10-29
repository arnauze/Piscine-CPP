#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include "Intern.hpp"
# include "Bureaucrat.hpp"

class                       OfficeBlock {
    public:
        OfficeBlock(void);
        OfficeBlock(Intern *intern, Bureaucrat *SBureaucrat, Bureaucrat *EBureaucrat);
        ~OfficeBlock(void);

        void                setIntern(Intern &intern);
        void                setSBureaucrat(Bureaucrat &bureaucrat);
        void                setEBureaucrat(Bureaucrat &bureaucrat);
        void                doBureaucracy(std::string formName, std::string targetName);

    private:
        OfficeBlock(OfficeBlock const & office);
        OfficeBlock         &operator=(OfficeBlock const & office);
        Intern              *intern;
        Bureaucrat          *SBureaucrat;
        Bureaucrat          *EBureaucrat;

};

#endif