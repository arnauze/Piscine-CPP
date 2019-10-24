# include <iostream>
# include <fstream>
# include <string>
# include <cerrno>
# include <sys/stat.h>

bool                isDir(char *file) {
    struct stat     checker;

    if (stat(file, &checker) == 0)
        if (checker.st_mode & S_IFDIR)
            return true;
    return false;
}

void		        catStream(std::istream & Stream) {
	std::cout << Stream.rdbuf();
}

void                readFile(char *filename) {
    std::ifstream	infile(filename);

	if (infile.is_open()) {

		if (isDir(filename)) {
			std::cout << "cat: " << filename << ": "
					<< "Is a directory" << std::endl;
		} else {
            catStream(infile);
		}

	} else {
		std::cout << "cat: " << filename << ": "
		          << strerror(errno) << std::endl;
	}
}

void                readFiles(char **files) {
    int             i = 0;
    while (files[++i])
        readFile(files[i]);
}

int                 main(int argc, char **argv) {
    if (argc > 1)
        readFiles(argv);
    else 
        catStream(std::cin);
    return (0);
}