# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form(void) : name("default"), is_signed(false), sign_min(-1), ex_min(-1) {
    return ;
}

Form::Form(std::string name, int minSign, int minEx) : name(name), is_signed(false), sign_min(minSign), ex_min(minEx) {
    if (minSign > 150 || minEx > 150)
        throw Form::GradeTooLowException();
    else if (minSign <= 0 || minEx <= 0)
        throw Form::GradeTooHighException();
    return ;
}

Form::~Form(void) throw() {
    return ;
}

Form::Form(Form const & form) : name(form.name), is_signed(form.is_signed), sign_min(form.sign_min), ex_min(form.ex_min) {
    *this = form;
    return ;
}

Form                      &Form::operator=(Form const & form) {
    this->is_signed = form.is_signed;
    return *this;
}

std::string                 Form::getName(void) const {
    return this->name;
}

int                         Form::getMinSign(void) const {
    return this->sign_min;
}

int                         Form::getMinEx(void) const {
    return this->ex_min;
}

bool                        Form::isSigned(void) const {
    return this->is_signed;
}

void                        Form::beSigned(Bureaucrat & bureaucrat) {
    if (this->getMinSign() < bureaucrat.getGrade())
        throw Form::GradeTooLowException();
    else {
        bureaucrat.signForm(*this);
        this->is_signed = true;
    }
    return ;
}

std::ostream                &operator<<(std::ostream &out, Form const & form) {
    out << "Form " << form.getName() << ":\nMin grade to sign: " << form.getMinSign() << "\nMin grade to execute: " << form.getMinEx() << "\nIs signed: " << (form.isSigned() ? "true" : "false") << std::endl;
    return out;
}

Form::GradeTooHighException::GradeTooHighException(void) {
    return ;
}   

Form::GradeTooHighException::~GradeTooHighException(void) throw() {
    return ;
}

Form::GradeTooHighException::GradeTooHighException(Form::GradeTooHighException const & e) {
    *this = e;
    return ;
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(Form::GradeTooHighException const & e) {
    (void)e;
    return *this;
}

const char                        *Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

Form::GradeTooLowException::GradeTooLowException(void) {
    return ;
}   

Form::GradeTooLowException::~GradeTooLowException(void) throw(){
    return ;
}

Form::GradeTooLowException::GradeTooLowException(Form::GradeTooLowException const & e) {
    *this = e;
    return ;
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(Form::GradeTooLowException const & e) {
    (void)e;
    return *this;
}

const char                        *Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

Form::FormNotSigned::~FormNotSigned(void) throw(){
    return ;
}

Form::FormNotSigned::FormNotSigned(Form::FormNotSigned const & e) {
    *this = e;
    return ;
}

Form::FormNotSigned &Form::FormNotSigned::operator=(Form::FormNotSigned const & e) {
    (void)e;
    return *this;
}

const char                        *Form::FormNotSigned::what() const throw() {
    return "Form not signed";
}