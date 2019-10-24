#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
# include <sstream>


class Brain {

    public:
        Brain( void );
        Brain(int size, int power, std::string color);
        ~Brain( void );
        std::string            identify( void );

    private:
        int             _size;
        int             _power;
        std::string     _color;
};

#endif