# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("default"), grade(150) {
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade <= 0)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade = grade;
    return ;
}

Bureaucrat::~Bureaucrat(void) throw() {
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & bureaucrat) {
    *this = bureaucrat;
    return ;
}

Bureaucrat                      &Bureaucrat::operator=(Bureaucrat const & bureaucrat) {
    this->setGrade(bureaucrat.getGrade());
    return *this;
}

void                            Bureaucrat::setGrade(int grade) {
    this->grade = grade;
    return ;
}

std::string                     Bureaucrat::getName(void) const {
    return this->name;
}

int                             Bureaucrat::getGrade(void) const {
    return this->grade;
}

void                            Bureaucrat::incrementGrade(void) {
    if (this->getGrade() > 1)
        this->setGrade(this->getGrade() - 1);
    else
        throw Bureaucrat::GradeTooHighException();
    return ;
}

void                            Bureaucrat::decrementGrade(void) {
    if (this->getGrade() < 150)
        this->setGrade(this->getGrade() + 1);
    else
        throw Bureaucrat::GradeTooLowException();
    return ;
}

std::ostream                &operator<<(std::ostream &out, Bureaucrat const & bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return out;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {
    return ;
}   

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {
    return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(Bureaucrat::GradeTooHighException const & e) {
    *this = e;
    return ;
}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const & e) {
    (void)e;
    return *this;
}

const char                        *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {
    return ;
}   

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw(){
    return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(Bureaucrat::GradeTooLowException const & e) {
    *this = e;
    return ;
}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const & e) {
    (void)e;
    return *this;
}

const char                        *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}