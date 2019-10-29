# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(void) {

    // Bureaucrat      jeremy("Jeremy", 1);
    // Bureaucrat      victor("Victor", 150);
    // Form            form("Vote", 10, 6);

    // std::cout << jeremy;
    // std::cout << victor << std::endl;
    // std::cout << form << std::endl;;

    // form.beSigned(victor);
    // form.beSigned(jeremy);

    // std::cout << std::endl << form;

    try {
        
        Bureaucrat      jeremy("Jeremy", 1);
        Bureaucrat      victor("Victor", 150);
        Form            form("Vote", 10, 6);
        // Form            form2("Vote", 151, 6);

        std::cout << jeremy;
        std::cout << victor << std::endl;
        std::cout << form << std::endl;;

        // form.beSigned(victor);
        form.beSigned(jeremy);

        std::cout << std::endl << form;

    } catch(std::exception &e) {

        std::cout << e.what() << std::endl;

    }

}