# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Presidential", 25, 5), target("default") {
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential", 25, 5), target(target){
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & form) : Form("Presidential", 25, 5) {
    *this = form;
    return ;
}

PresidentialPardonForm          &PresidentialPardonForm::operator=(PresidentialPardonForm const & form) {
    this->target = form.target;
    return *this;
}

void                            PresidentialPardonForm::setTarget(std::string const & target) {
    this->target = target;
    return ;
}

std::string                     PresidentialPardonForm::getTarget(void) const {
    return this->target;
}

void                            PresidentialPardonForm::execute(Bureaucrat const & bureaucrat) const {
    if (bureaucrat.getGrade() > this->getMinEx())
        throw Bureaucrat::GradeTooLowException();
    // if (!this->isSigned())
    //     throw Form::FormNotSigned();
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}