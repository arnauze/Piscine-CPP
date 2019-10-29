# include "Bureaucrat.hpp"

int main(void) {

    // Bureaucrat      arnaud("Arnaud", 100);
    // std::cout << arnaud;
    // Bureaucrat      victor("Victor", 200);
    // std::cout << arnaud;

    // try {
    //     Bureaucrat      arnaud("Arnaud", 100);
    //     std::cout << arnaud;
    //     Bureaucrat      victor("Victor", 200);
    //     std::cout << arnaud;
    // } catch(std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }

    // Bureaucrat      arnaud("Arnaud", 149);
    // std::cout << arnaud;
    // arnaud.decrementGrade();
    // std::cout << arnaud;
    // arnaud.decrementGrade();
    // std::cout << arnaud;

    try {
        Bureaucrat      arnaud("Arnaud", 149);
        std::cout << arnaud;
        arnaud.incrementGrade();
        std::cout << arnaud;
        arnaud.decrementGrade();
        std::cout << arnaud;
        arnaud.decrementGrade();
        std::cout << arnaud;
        arnaud.decrementGrade();
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

}