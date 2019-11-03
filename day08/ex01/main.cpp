# include "span.hpp"

# define LOOPS  10
# define SIZE   10

int     main(void) {
    Span        span(SIZE);
    try {

        for(int i = 0; i < LOOPS; i++) {
            span.addNumber(i + 1);
        }
        std::cout << span.longestSpan() << std::endl;
        std::cout << span.shortestSpan() << std::endl;

    } catch (std::exception & e) {

        std::cout << "Exception: " << e.what() << std::endl;

    }
    return (0);
}