# include "easyfind.hpp"

int main(void) {
    std::list<int>     array;
    for(int i = 0; i < 10; i++) {
        array.push_back(i);
    }
    int x = 12;
    try {
        std::cout << easyfind(array, x) << std::endl;
    } catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return (0);
}