# include <climits>
# include <cmath>
# include <iostream>

void            printChar(double value) {
    std::cout << "char: ";
    if (std::isnan(value))
        std::cout << "Impossible" << std::endl;
    else if (value > 126 || value < 32)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << static_cast<char>(value) << std::endl;;
}

void            printInt(double value) {
    std::cout << "int: ";
    if (value < INT_MIN || value > INT_MAX || std::isnan(value))
        std::cout << "Impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

void            printFloat(double value) {
    std::cout << "float: ";
    if (floor(value) == value)
        std::cout << static_cast<float>(value) << ".0f" << std::endl;
    else
        std::cout << static_cast<float>(value) << "f" << std::endl;
}

void            printDouble(double value) {
    std::cout << "double: ";
    if (floor(value) == value)
        std::cout << value << ".0" << std::endl;
    else
        std::cout << value << std::endl;
}

int             main(int argc, char **argv) {
    if (argc != 2)
        std::cout << "usage: ./extract <string>" << std::endl;
    else {
        double          value = std::stod(argv[1]);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
    }
}