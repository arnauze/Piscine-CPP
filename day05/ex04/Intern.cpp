# include "Intern.hpp"

Intern::Intern(void) {
    return ;
}

Intern::~Intern(void){
    return ;
}

Intern::Intern(Intern const & intern) {
    *this = intern;
    return ;
}

Intern          Intern::operator=(Intern const & intern) {
    (void)intern;
    return *this;
}

Form            *Intern::makeForm(std::string type, std::string target) {
    if (type == "presidential pardon") {
        std::cout << "Intern creates " << type << std::endl;
        return new PresidentialPardonForm(target);
    }
    else if (type == "robotomy request") {
        std::cout << "Intern creates " << type << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (type == "shruberry creation") {
        std::cout << "Intern creates " << type << std::endl;
        return new ShruberryCreationForm(target);
    }
    else
        std::cout << "Intern can't create an unknown form." << std::endl;
    return NULL;
}