#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class                   FragTrap : public ClapTrap {
    public:
        FragTrap( std::string const & name );
        FragTrap( void );
        ~FragTrap( void );
        FragTrap( FragTrap const & frag );
        FragTrap        &operator=(FragTrap const & frag);

        void            vaulthunter_dot_exe(std::string const & target);
        void            vaulthunter_dot_exe(FragTrap *target);
        void            beerThrowing(FragTrap *target);
        void            taunt(FragTrap *target);
        void            takesAPeeBreak(FragTrap *target);
        void            spits(FragTrap *target);
        void            rpg(FragTrap *target);
        void            meleeAttack(FragTrap *ennemy);
        void            rangedAttack(FragTrap *ennemy);
};

#endif