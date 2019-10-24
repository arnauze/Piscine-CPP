# include "FragTrap.hpp"

typedef struct {
    void            (FragTrap::*func)(FragTrap *target);
}                   dispatch_t;


FragTrap::FragTrap( std::string const & name ) : _name(name) {
    std::cout << "My name is " << name << " how can I help?" << std::endl;
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

FragTrap::FragTrap( FragTrap const & frag ) {
    *this = frag;
    std::cout << "My name is " << this->getName() << " how can I help?" << std::endl;
    return ;
}

FragTrap &      FragTrap::operator=(FragTrap const & frag) {
    std::cout << "My name is " << frag._name << " how can I help?" << std::endl;
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

void            FragTrap::rangedAttack(std::string const & target) {
    std::cout << "FR4G-TPt " << this->getName() << " attacks " << target << " at range, causing " << this->getRangedDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
}

void            FragTrap::rangedAttack(FragTrap *ennemy) {
    std::cout << "FR4G-TPt " << this->getName() << " attacks " << ennemy->getName() << " at range, causing " << this->getRangedDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
    ennemy->takeDamage(this->getRangedDamage());
}

void            FragTrap::meleeAttack(std::string const & target) {
    std::cout << "FR4G-TPt " << this->getName() << " attacks " << target << " at melee, causing " << this->getMeleeDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
}

void            FragTrap::meleeAttack(FragTrap  *ennemy) {
    std::cout << "FR4G-TPt " << this->getName() << " attacks " << ennemy->getName() << " at melee, causing " << this->getMeleeDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
    ennemy->takeDamage(this->getMeleeDamage());
}

std::string     FragTrap::appendName(void) {
    std::stringstream oss;
    oss << this->getName() << ": ";
    return oss.str();
}

void            FragTrap::takeDamage(unsigned int amount) {
    if ((this->_hitPoints - (amount - this->getArmorReduction())) < 0)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= (amount - this->getArmorReduction());
}

void            FragTrap::beRepaired(unsigned int amount) {
    if ((this->_hitPoints + amount) > 100)
        this->_hitPoints = 100;
    else
        this->_hitPoints += amount;
}

void            FragTrap::beerThrowing(FragTrap *target) {
    std::cout << this->appendName() << std::endl << "*throws a beer*" << std::endl << "You take 5 damage. You're lucky he can't aim..." << std::endl;
    target->takeDamage(10);
}

void            FragTrap::taunt(FragTrap *target) {
    (void)*target;
    std::cout << this->appendName() << std::endl << "If you came out of your mom feet first then at some point you wore her as a hat." << std::endl;
}

void            FragTrap::takesAPeeBreak(FragTrap *target) {
    std::cout << this->appendName() << std::endl << "Wait a minute please, gotta go pee. Be right back." << std::endl << "*disappears for a minute*" << std::endl << "*red dot appears on your arm*" << std::endl << "*shoot*" << std::endl << "You take 75 damages. ALWAYS BE CAREFUL" << std::endl;
    target->takeDamage(80);
}

void            FragTrap::spits(FragTrap *target) {
    std::cout << this->appendName() << std::endl << "*spits on your brand new sneakers*" << std::endl << "You take 99 damage (you're very emotional)" << std::endl;
    target->takeDamage(104);
}

void            FragTrap::rpg(FragTrap *target) {
    std::cout << this->appendName() << std::endl << "*Takes a RPG out of his pocket*" << std::endl << "*shoots on a dog walking by*" << std::endl << "That was close." << std::endl << "You take 0 dmg" << std::endl;
    (void)target;
}

void            FragTrap::vaulthunter_dot_exe(std::string const & target) {
    (void)target;
    return ;
}

void            FragTrap::vaulthunter_dot_exe(FragTrap *target) {

    dispatch_t  dispatchTable[5] = {
        {&FragTrap::beerThrowing},
        {&FragTrap::taunt},
        {&FragTrap::takesAPeeBreak},
        {&FragTrap::spits},
        {&FragTrap::rpg}
    };
    
    srand(time(NULL));
    int x = rand() % 5;
    (*this.*dispatchTable[x].func)(target);
}

int             FragTrap::getHitPoints(void) {
    return this->_hitPoints;
}

int             FragTrap::getMaxHitPoints(void) {
    return this->_maxHitPoints;
}

int             FragTrap::getEnergyPoints(void) {
    return this->_energyPoints;
}

int             FragTrap::getMaxEnergyPoints(void) {
    return this->_maxEnergyPoints;
}

int             FragTrap::getLevel(void) {
    return this->_level;
}

std::string     FragTrap::getName(void) {
    return this->_name;
}

int             FragTrap::getMeleeDamage(void) {
    return this->_meleeDamage;
}

int             FragTrap::getRangedDamage(void) {
    return this->_rangedDamage;
}

int             FragTrap::getArmorReduction(void) {
    return this->_armorReduction;
}

void            FragTrap::getInfos(void) {
    std::cout << std::endl
    << "FragTap called " << this->getName() << std::endl
    << "HP: " << this->getHitPoints() << std::endl
    << "Energy: " << this->getEnergyPoints() << std::endl
    << "Level: " << this->getLevel() << std::endl
    << "Armor reduction: " << this->getArmorReduction() << std::endl
    << std::endl;
}