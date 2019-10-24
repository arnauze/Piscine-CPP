#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <fstream>
# include <cmath>
# include <string>

class Fixed {

    private:
        int                 _value;
        static const int    _fractional = 8;

    public:
        Fixed( void );
        ~Fixed( void );
        Fixed( Fixed const & elem );
        Fixed( int const n );
        Fixed( float const f );
        float               toFloat( void ) const;
        int                 toInt( void ) const;
        Fixed &             operator=(Fixed const & elem);
        int                 getRawBits( void ) const;
        void                setRawBits(int const raw);

};

std::ostream    &           operator<<(std::ostream & o, Fixed const &f);

#endif