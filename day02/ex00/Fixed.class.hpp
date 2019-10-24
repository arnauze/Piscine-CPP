#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <string>
# include <iostream>

class Fixed {

    private:
        int                 _value;
        static const int    _fractional = 8;

    public:
        Fixed( void );
        ~Fixed( void );
        Fixed( Fixed const & elem );
        Fixed &             operator=(Fixed const & elem);
        int                 getRawBits( void ) const;
        void                setRawBits(int const raw);

};

#endif