# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShruberryCreationForm.hpp"

int main(void) {

    Form        *form = new PresidentialPardonForm("Arnaud");
    Form        *form2 = new RobotomyRequestForm("Julie");
    Form        *form3 = new ShruberryCreationForm("Christophe");
    Bureaucrat  piston("Victor", 1);

    form->beSigned(piston);
    if (piston.executeForm(*form))
        form->execute(piston);

    form2->beSigned(piston);
    if (piston.executeForm(*form2))
        form2->execute(piston);

    form3->beSigned(piston);
    if (piston.executeForm(*form3))
        form3->execute(piston);

    return (0);

}