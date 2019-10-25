# include "NinjaTrap.hpp"

typedef struct {
    std::string     type;
    void            (NinjaTrap::*func)(ClapTrap &ennemy);
}                   dispatch_t;

NinjaTrap::NinjaTrap(void) : ClapTrap("default") {
    srand(time(NULL));
    std::cout << "NinjaTrap called " << this->_name << " and ready for duty." << std::endl;
    return ;
}

NinjaTrap::NinjaTrap( std::string const & name ) : ClapTrap(name) {
    std::cout << "NinjaTrap called " << name << " and ready for duty." << std::endl;
    srand(time(NULL));
    this->_hitPoints = 60;
    this->_maxHitPoints = 60;
    this->_energyPoints = 120;
    this->_maxEnergyPoints = 120;
    this->_level = 1;
    this->_meleeDamage = 60;
    this->_rangedDamage = 5;
    this->_armorReduction = 0;
    return ;
}

NinjaTrap::~NinjaTrap( void ) {
    std::cout << "NinjaTrap " << this->getName() << " has died serving his country" << std::endl;
    return ;
}

NinjaTrap::NinjaTrap( NinjaTrap const & frag ) : ClapTrap(frag) {
    *this = frag;
    std::cout << "NinjaTrap called " << frag._name << " and ready for duty." << std::endl;
    return ;
}

NinjaTrap &      NinjaTrap::operator=(NinjaTrap const & frag) {
    std::cout << "Operator overload = called" << std::endl;
    this->_hitPoints = frag._hitPoints;
    this->_maxHitPoints = frag._maxHitPoints;
    this->_energyPoints = frag._energyPoints;
    this->_maxEnergyPoints = frag._maxEnergyPoints;
    this->_level = frag._level;
    this->_meleeDamage = frag._meleeDamage;
    this->_rangedDamage = frag._rangedDamage;
    this->_armorReduction = frag._armorReduction;
    return *this;
}

void            NinjaTrap::rangedAttack(NinjaTrap *ennemy) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << "NinjaTrap " << this->getName() << " attacks " << ennemy->getName() << " at range, causing " << this->getRangedDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
        ennemy->takeDamage(this->getRangedDamage());
        this->looseEnergy(25);
    }
}

void            NinjaTrap::meleeAttack(NinjaTrap  *ennemy) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << "NinjaTrap " << this->getName() << " attacks " << ennemy->getName() << " at melee, causing " << this->getMeleeDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
        ennemy->takeDamage(this->getMeleeDamage());
        this->looseEnergy(25);
    }
}

void            NinjaTrap::meleeAttack(std::string const & target) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {   
        std::cout << "NinjaTrap " << this->getName() << " attacks " << target << " at melee, causing " << this->getMeleeDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
    }
}

void            NinjaTrap::rangedAttack(std::string const & target) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << "NinjaTrap " << this->getName() << " attacks " << target << " at range, causing " << this->getRangedDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
    }
}


void            NinjaTrap::box1(ClapTrap &ennemy) {
    std::cout << "Hello Ninja ! Don't approach or I'll drain your little " << ennemy.getHitPoints() << " HP." << std::endl;
    return ;
}

void            NinjaTrap::box2(ClapTrap &ennemy) {
    std::cout << "Hello Frag ! Don't approach or I'll drain your little " << ennemy.getHitPoints() << " HP." << std::endl;
    return ;
}

void            NinjaTrap::box3(ClapTrap &ennemy) {
    std::cout << "Hello Scav ! Don't approach or I'll drain your little " << ennemy.getHitPoints() << " HP." << std::endl;
    return ;
}

void            NinjaTrap::ninjaShoeBox(ClapTrap &ennemy) {
    std::string     type = ennemy.getType();
    dispatch_t      dispatch[3] = {
        {"NinjaTrap", &NinjaTrap::box1},
        {"FragTrap", &NinjaTrap::box2},
        {"ScavTrap", &NinjaTrap::box3}
    };
    int             i = -1;

    while (++i < 3) {
        if (dispatch[i].type == type) {
            (this->*dispatch[i].func)(ennemy);  
        }
    }
}

std::string NinjaTrap::getType(void) const {
    return std::string("NinjaTrap");
}