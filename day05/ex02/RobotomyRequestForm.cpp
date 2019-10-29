# include "RobotomyRequestForm.hpp"
# include <time.h>

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy", 72, 45), target("default") {
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy", 72, 45), target(target) {
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & form) : Form("Robotomy", 72, 45) {
    *this = form;
    return ;
}

RobotomyRequestForm          &RobotomyRequestForm::operator=(RobotomyRequestForm const & form) {
    this->target = form.getTarget();
    return *this;
}

void                            RobotomyRequestForm::setTarget(std::string const & target) {
    this->target = target;
    return ;
}

std::string                     RobotomyRequestForm::getTarget(void) const {
    return this->target;
}

void                            RobotomyRequestForm::execute(Bureaucrat const & bureaucrat) const {
    if (bureaucrat.getGrade() > this->getMinEx())
        throw Bureaucrat::GradeTooLowException();
    // if (!this->isSigned())
    //     throw Form::FormNotSigned();
    srand(time(NULL));
    int x = rand() % 2;
    std::cout << "*Vrrrrrrrrrr*" << std::endl << "[...]" << std::endl;
    if (x == 1)
        std::cout << this->getTarget() << " has been robotomized !" << std::endl;
    else
        std::cout << this->getTarget() << " has exploded." << std::endl;
}