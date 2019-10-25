#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class                   ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap( std::string const & name );
        ScavTrap( void );
        ~ScavTrap( void );
        ScavTrap( ScavTrap const & frag );
        ScavTrap        &operator=(ScavTrap const & frag);

        void            rangedAttack(ScavTrap *ennemy);
        void            rangedAttack(std::string const & target);
        void            meleeAttack(ScavTrap *ennemy);
        void            meleeAttack(std::string const & target);
        void            challengeNewcomer(std::string const & target);
        void            firstChallenge(std::string const & target);
        void            secondChallenge(std::string const & target);
        void            thirdChallenge(std::string const & target);
        void            fourthChallenge(std::string const & target);
        void            fifthChallenge(std::string const & target);

       std::string      getType(void) const;
};

#endif
