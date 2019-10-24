# include <string>
# include <iostream>
# include <fstream>
# include <sstream>

int     main(int argc, char **argv) {
    if (argc != 4) {

        std::cout << "usage: ./replace filename str_to_replace str_replacing" << std::endl;
        return (-1);

    } else {

        if ((std::strlen(argv[1]) < 1) || (std::strlen(argv[2]) < 1) || (std::strlen(argv[3]) < 1)) {
            std::cout << "Arguments can't be empty" << std::endl;
            return (-1);
        }

        std::ifstream       inputFile(argv[1]);
        std::string         toReplace(argv[2]);
        std::string         replacing(argv[3]);
        std::string         line;

        if (inputFile.is_open()) {

            std::stringstream   outputFileName;
            outputFileName << argv[1] << ".replace";
            std::ofstream       outputFile(outputFileName.str());

            if (outputFile.is_open()) {

                while(std::getline(inputFile, line)) {

                    while (line.find(toReplace) != std::string::npos) {

                        line.replace(line.find(toReplace), toReplace.length(), replacing);

                    }
                    
                    outputFile << line << '\n';
                }

            }

        } else std::cout << "Error opening the file. Check filename" << std::endl;

    }
    return (0);
}