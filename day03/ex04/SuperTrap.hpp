#ifndef SUPER_TRAP_HPP
# define SUPER_TRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class           SuperTrap : public FragTrap, public NinjaTrap {

    public:
        SuperTrap( void );
        SuperTrap(std::string const & name);
        ~SuperTrap( void );
        SuperTrap( SuperTrap const & s );
        SuperTrap        &operator=(SuperTrap const & s );

        std::string     getType(void) const;
        void            meleeAttack(std::string const & target);
        void            rangedAttack(std::string const & target);

};

#endif