#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"

class                               NinjaTrap : public ClapTrap {

    public:
        NinjaTrap( std::string const & name );
        NinjaTrap( void );
        ~NinjaTrap( void );
        NinjaTrap( NinjaTrap const & frag );
        NinjaTrap                   &operator=(NinjaTrap const & frag);

        void                        rangedAttack(NinjaTrap *ennemy);
        void                        meleeAttack(NinjaTrap *ennemy);
        void                        ninjaShoeBox(ClapTrap &ennemy);

        void                        box1(ClapTrap &ennemy);
        void                        box2(ClapTrap &ennemy);
        void                        box3(ClapTrap &ennemy);

        std::string                 getType(void) const;

};

#endif