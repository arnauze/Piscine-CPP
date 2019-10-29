#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class                               Cure : public AMateria{

    public:
        Cure( void );
        ~Cure( void );
        Cure( Cure const & cure );
        Cure &operator=(Cure const & cure);
        
        AMateria*                   clone() const;
        void                        use(ICharacter& target);
};

#endif