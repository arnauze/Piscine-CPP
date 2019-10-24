#ifndef PONY_CLASS_HPP
# define PONY_CLASS_HPP

# include <string>
# include <iostream>
# include <cctype>
# include <iomanip>

class           Pony {

    public:
        std::string     name;
        std::string     color;
        std::string     gender;
        Pony( std::string name, std::string color, std::string gender );
        ~Pony( void );
};

#endif