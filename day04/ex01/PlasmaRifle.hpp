#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "header.hpp"
# include "AWeapon.hpp"

class        PlasmaRifle : public AWeapon {

    public:
        PlasmaRifle(void);
        ~PlasmaRifle( void );
        PlasmaRifle( PlasmaRifle const & pRifle );
        PlasmaRifle &operator=(PlasmaRifle const & pRifle);

        void        attack(void);

};

#endif