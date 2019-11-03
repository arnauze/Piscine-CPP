# include <iostream>
# include "Array.hpp"

int                 main() {

     Array<int> test(5);
    //Array<int> test;

    try {
        std::cout << test[2] << std::endl;
		std::cout << test.getSize() << std::endl;
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
