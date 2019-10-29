# include "Intern.hpp"

int main(void) {

    Intern          someRandomIntern;
    Bureaucrat      arnaud("Arnaud", 1);
    Form            *rrf;
    Form            *rrf2;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    rrf2 = someRandomIntern.makeForm("presidential pardon", "Armand");
    std::cout << std::endl;

    std::cout << *rrf;
    std::cout << *rrf2;
    std::cout << std::endl;

    rrf->beSigned(arnaud);
    rrf2->beSigned(arnaud);
    std::cout << std::endl;

    std::cout << *rrf;
    std::cout << *rrf2;

    std::cout << std::endl;

    if (arnaud.executeForm(*rrf))
        rrf->execute(arnaud);
    std::cout << std::endl;
    if (arnaud.executeForm(*rrf2))
        rrf2->execute(arnaud);

    return (0);

}