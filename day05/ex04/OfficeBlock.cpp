# include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void) { return ; }

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *SBureaucrat, Bureaucrat *EBureaucrat) : intern(intern), SBureaucrat(SBureaucrat), EBureaucrat(EBureaucrat) { return ; }

OfficeBlock::~OfficeBlock(void) { return ; }

OfficeBlock::OfficeBlock(OfficeBlock const & office) { (void)office; return ; }

OfficeBlock     &OfficeBlock::operator=(OfficeBlock const & office) { (void)office; return *this; }

void            OfficeBlock::setIntern(Intern &intern) {
    this->intern = &intern;
    return;
}

void            OfficeBlock::setSBureaucrat(Bureaucrat &bureaucrat) {
    this->SBureaucrat = &bureaucrat;
    return;
}

void            OfficeBlock::setEBureaucrat(Bureaucrat &bureaucrat) {
    this->EBureaucrat = &bureaucrat;
    return;
}

void            OfficeBlock::doBureaucracy(std::string formName, std::string targetName) {
    if (!this->intern || !this->SBureaucrat || !this->EBureaucrat)
        std::cout << "You need to completely fill your office before processing any files!" << std::endl;
    else {
        Form    *form;
        form = this->intern->makeForm(formName, targetName);
        form->beSigned(*(this->SBureaucrat));
        if (this->EBureaucrat->executeForm(*form))
            form->execute(*(this->EBureaucrat));
    }
    return ;
}