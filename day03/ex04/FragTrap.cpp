# include "FragTrap.hpp"

typedef struct {
    void            (FragTrap::*func)(FragTrap *target);
}                   dispatch_t;

FragTrap::FragTrap(void) : ClapTrap("default") {
    srand(time(NULL));
    std::cout << "My name is " << this->_name << " how can I help?" << std::endl;
    return ;
}

FragTrap::FragTrap( std::string const & name ) : ClapTrap(name) {
    std::cout << "My name is " << name << " how can I help?" << std::endl;
    srand(time(NULL));
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 100;
    this->_maxEnergyPoints = 100;
    this->_level = 1;
    this->_meleeDamage = 30;
    this->_rangedDamage = 20;
    this->_armorReduction = 5;
    return ;
}

FragTrap::~FragTrap( void ) {
    std::cout << "NOOOOOOOOOOOOOOO\n*explodes*" << std::endl << "*city explodes*" << std::endl << "*planet explodes*" << std::endl << "*Solar system desintegrates*" << std::endl << std::endl;
    return ;
}

FragTrap::FragTrap( FragTrap const & frag ) : ClapTrap(frag) {
    *this = frag;
    std::cout << "My name is " << this->getName() << " how can I help?" << std::endl;
    return ;
}

FragTrap &      FragTrap::operator=(FragTrap const & frag) {
    std::cout << "Operator overload = called" << std::endl;
    this->_name = frag._name;
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

void            FragTrap::rangedAttack(FragTrap *ennemy) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << "FR4G-TPt " << this->getName() << " attacks " << ennemy->getName() << " at range, causing " << this->getRangedDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
        ennemy->takeDamage(this->getRangedDamage());
        this->looseEnergy(25);
    }
}

void            FragTrap::meleeAttack(FragTrap  *ennemy) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << "FR4G-TPt " << this->getName() << " attacks " << ennemy->getName() << " at melee, causing " << this->getMeleeDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
        ennemy->takeDamage(this->getMeleeDamage());
        this->looseEnergy(25);
    }
}

void            FragTrap::meleeAttack(std::string const & target) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {   
        std::cout << "FR4G-TPt " << this->getName() << " attacks " << target << " at melee, causing " << this->getMeleeDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
    }
}

void            FragTrap::rangedAttack(std::string const & target) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << "FR4G-TPt " << this->getName() << " attacks " << target << " at range, causing " << this->getRangedDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
    }
}

void            FragTrap::beerThrowing(FragTrap *target) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << this->appendName() << std::endl << "*throws a beer*" << std::endl << "You take 5 damage. You're lucky he can't aim..." << std::endl;
        target->takeDamage(10);
        this->looseEnergy(25);
    }
}

void            FragTrap::taunt(FragTrap *target) {
    (void)*target;
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << this->appendName() << std::endl << "If you came out of your mom feet first then at some point you wore her as a hat." << std::endl;
        this->looseEnergy(25);
    }
}

void            FragTrap::takesAPeeBreak(FragTrap *target) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {
        std::cout << this->appendName() << std::endl << "Wait a minute please, gotta go pee. Be right back." << std::endl << "*disappears for a minute*" << std::endl << "*red dot appears on your arm*" << std::endl << "*shoot*" << std::endl << "You take 75 damages. ALWAYS BE CAREFUL" << std::endl;
        target->takeDamage(80);
        this->looseEnergy(25);
    }
}

void            FragTrap::spits(FragTrap *target) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << this->appendName() << std::endl << "*spits on your brand new sneakers*" << std::endl << "You take 99 damage (you're very emotional)" << std::endl;
        target->takeDamage(104);
        this->looseEnergy(25);
    }
}

void            FragTrap::rpg(FragTrap *target) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << this->appendName() << std::endl << "*Takes a RPG out of his pocket*" << std::endl << "*shoots on a dog walking by*" << std::endl << "That was close." << std::endl << "You take 0 dmg" << std::endl;
        this->looseEnergy(25);
        (void)target;
    }
}

void            FragTrap::vaulthunter_dot_exe(std::string const & target) {
    (void)target;
    return ;
}

void            FragTrap::vaulthunter_dot_exe(FragTrap *target) {

    dispatch_t  dispatchTable[7] = {
        {&FragTrap::beerThrowing},
        {&FragTrap::taunt},
        {&FragTrap::takesAPeeBreak},
        {&FragTrap::spits},
        {&FragTrap::rpg},
        {&FragTrap::rangedAttack},
        {&FragTrap::meleeAttack}
    };

    int x = rand() % 7;
    (this->*dispatchTable[x].func)(target);    
}

std::string     FragTrap::getType(void) const {
    return std::string("FragTrap");
}