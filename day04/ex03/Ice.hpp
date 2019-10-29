#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class                               Ice : public AMateria{

    public:
        Ice( void );
        ~Ice( void );
        Ice( Ice const & ice );
        Ice &operator=(Ice const & ice);
        
        AMateria*                   clone() const;
        void                        use(ICharacter& target);
};

#endif