#include <iostream>
#include <cctype>

int     main(int argc, char **argv)
{
    int i;
    int j;

    if (argc > 1) {

        i = 0;
        while (argv[++i]) {
            j = -1;
            while (argv[i][++j]) {
                putchar(toupper(argv[i][j]));
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return 0;
}