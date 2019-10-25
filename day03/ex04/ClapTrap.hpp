#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <ctime>

class                   ClapTrap {
    public:
        ClapTrap ( std::string const & name );
        ClapTrap( void );
        ~ClapTrap ( void );
        ClapTrap ( ClapTrap const & frag );
        ClapTrap        &operator=(ClapTrap const & frag);

        virtual void    rangedAttack(std::string const & target) = 0;
        virtual void    meleeAttack(std::string const & target) = 0;
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);
        void            looseEnergy(unsigned int amount);

        int             getHitPoints(void);
        int             getMaxHitPoints(void);
        int             getEnergyPoints(void);
        int             getMaxEnergyPoints(void);
        int             getLevel(void);
        std::string     getName(void);
        int             getMeleeDamage(void);
        int             getRangedDamage(void);
        int             getArmorReduction(void);

        std::string     appendName(void);
        void            getInfos(void);

        virtual std::string    getType(void) const = 0;

    protected:
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