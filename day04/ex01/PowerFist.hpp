#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "header.hpp"
# include "AWeapon.hpp"

class        PowerFist : virtual public AWeapon {

    public:
        PowerFist(void);
        ~PowerFist( void );
        PowerFist( PowerFist const & pRifle );
        PowerFist &operator=(PowerFist const & pRifle);

        void        attack(void) const;

};

#endif