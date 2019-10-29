# include "Intern.hpp"
# include "OfficeBlock.hpp"

int main(void) {

    // Intern          someRandomIntern;
    // Bureaucrat      arnaud("Arnaud", 1);
    // Bureaucrat      felix("Felix", 1);
    // OfficeBlock     office(someRandomIntern, arnaud, felix);

    // office.doBureaucracy("presidential pardon", "Julie");

    try {

        Intern          someRandomIntern;
        Bureaucrat      arnaud("Arnaud", 100);
        Bureaucrat      felix("Felix", 1);
        OfficeBlock     office;

        office.doBureaucracy("presidential pardon", "Julie");

        office.setIntern(someRandomIntern);
        office.setSBureaucrat(arnaud);
        office.setEBureaucrat(felix);

        office.doBureaucracy("shruberry creation", "Julie");

    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return (0);

}