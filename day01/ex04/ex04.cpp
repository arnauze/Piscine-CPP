# include <string>
# include <iostream>

int         main(void) {
    std::string         str = "HI THIS IS BRAIN";
    std::string *       strPointer = &str;
    std::string &       strRef = str;

    std::cout << *strPointer << std::endl;
    std::cout << strRef << std::endl;
}