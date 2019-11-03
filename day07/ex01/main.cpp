# include <string>
# include <iostream>

template<typename T>
void        iter(T const *array, int length, void   (*f)(T const & elem)) {
    int     i = -1;

    while (++i < length) {
        f(array[i]);
    }
}

template<typename T>
void        showElem(T const & elem) {
    std::cout << elem << std::endl;
}

int         main(void) {
    int     array[] = {10, 27, 2, 3, 4, 5, 42, 74};
    std::string     stringArray[] = {"Arnaud", "Victor", "Felix", "Raymond"};

    iter(array, 8, &showElem);
    std::cout << std::endl;
    iter(stringArray, 4, &showElem);
    return (0);
}