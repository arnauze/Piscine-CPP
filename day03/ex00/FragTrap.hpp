#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include <sstream>

class                   FragTrap {
    public:
        FragTrap( std::string const & name );
        ~FragTrap( void );
        FragTrap( FragTrap const & frag );
        FragTrap        &operator=(FragTrap const & frag);

        void            rangedAttack(std::string const & target);
        void            rangedAttack(FragTrap *ennemy);
        void            meleeAttack(std::string const & target);
        void            meleeAttack(FragTrap *ennemy);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);
        void            vaulthunter_dot_exe(std::string const & target);
        void            vaulthunter_dot_exe(FragTrap *target);

        int             getHitPoints(void);
        int             getMaxHitPoints(void);
        int             getEnergyPoints(void);
        int             getMaxEnergyPoints(void);
        int             getLevel(void);
        std::string     getName(void);
        int             getMeleeDamage(void);
        int             getRangedDamage(void);
        int             getArmorReduction(void);

        void            beerThrowing(FragTrap *target);
        void            taunt(FragTrap *target);
        void            takesAPeeBreak(FragTrap *target);
        void            spits(FragTrap *target);
        void            rpg(FragTrap *target);

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