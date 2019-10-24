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
        bool                operator<(Fixed const & elem);
        bool                operator<=(Fixed const & elem);
        bool                operator>(Fixed const & elem);
        bool                operator>=(Fixed const & elem);
        bool                operator==(Fixed const & elem);
        bool                operator!=(Fixed const & elem);
        Fixed               operator+(Fixed const & elem);
        Fixed               operator-(Fixed const & elem);
        Fixed               operator*(Fixed const & elem);
        Fixed               operator/(Fixed const & elem);
        Fixed &             operator++(void);
        Fixed               operator++(int n);
        Fixed &             operator--(void);
        Fixed               operator--(int n);
        int                 getRawBits( void ) const;
        void                setRawBits(int const raw);
        static Fixed        &min(Fixed &a, Fixed &b);
        static const Fixed  &min(Fixed const &a, Fixed const &b);
        static Fixed        &max(Fixed &a, Fixed &b);
        static const Fixed  &max(Fixed const &a, Fixed const &b);    

};

std::ostream    &           operator<<(std::ostream & o, Fixed const &f);

#endif