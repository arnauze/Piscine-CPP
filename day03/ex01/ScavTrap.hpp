#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "FragTrap.hpp"

class                   ScavTrap {
    public:
        ScavTrap( std::string const & name );
        ScavTrap(void);
        ~ScavTrap( void );
        ScavTrap( ScavTrap const & frag );
        ScavTrap        &operator=(ScavTrap const & frag);

        void            rangedAttack(std::string const & target);
        void            rangedAttack(ScavTrap *ennemy);
        void            meleeAttack(std::string const & target);
        void            meleeAttack(ScavTrap *ennemy);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);
        void            looseEnergy(unsigned int amount);
        void            challengeNewcomer(std::string const & target);

        int             getHitPoints(void);
        int             getMaxHitPoints(void);
        int             getEnergyPoints(void);
        int             getMaxEnergyPoints(void);
        int             getLevel(void);
        std::string     getName(void);
        int             getMeleeDamage(void);
        int             getRangedDamage(void);
        int             getArmorReduction(void);

        void            firstChallenge(std::string const & target);
        void            secondChallenge(std::string const & target);
        void            thirdChallenge(std::string const & target);
        void            fourthChallenge(std::string const & target);
        void            fifthChallenge(std::string const & target);

        std::string     appendName(void);
        void            getInfos(void);

    private:
        int             _hitPoints;
        int             _maxHitPoints;
        int             _energyPoints;
        int             _maxEnergyPoints;
        int             _level;
        std::string     _name;
        int             _meleeDamage;
        int             _rangedDamage;
        int             _armorReduction;

};

#endif
