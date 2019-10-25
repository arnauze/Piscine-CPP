# include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("default") {
    std::cout << "Parent class ClapTrap with name " << this->_name << " created" << std::endl;
    return ;
}

ClapTrap::ClapTrap( std::string const & name ) : _name(name) {
    std::cout << "Parent class ClapTrap with name " << name << " created" << std::endl;
    return ;
}

ClapTrap::~ClapTrap( void ) {
    std::cout << "Parent class ClapTrap with name " << this->getName() << " estroyed" << std::endl;
    return ;
}

ClapTrap::ClapTrap ( ClapTrap const & frag ) {
    std::cout << "Parent class ClapTrap with name " << frag._name << " created" << std::endl;
    *this = frag;
    return ;
}

ClapTrap        &ClapTrap::operator=(ClapTrap const & frag) {
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

int             ClapTrap::getHitPoints(void) {
    return this->_hitPoints;
}

int             ClapTrap::getMaxHitPoints(void) {
    return this->_maxHitPoints;
}

int             ClapTrap::getEnergyPoints(void) {
    return this->_energyPoints;
}

int             ClapTrap::getMaxEnergyPoints(void) {
    return this->_maxEnergyPoints;
}

int             ClapTrap::getLevel(void) {
    return this->_level;
}

std::string     ClapTrap::getName(void) {
    return this->_name;
}

int             ClapTrap::getMeleeDamage(void) {
    return this->_meleeDamage;
}

int             ClapTrap::getRangedDamage(void) {
    return this->_rangedDamage;
}

int             ClapTrap::getArmorReduction(void) {
    return this->_armorReduction;
}

void            ClapTrap::getInfos(void) {
    std::cout << std::endl
    << "Name: " << this->getName() << std::endl
    << "HP: " << this->getHitPoints() << std::endl
    << "Energy: " << this->getEnergyPoints() << std::endl
    << "Level: " << this->getLevel() << std::endl
    << "Armor reduction: " << this->getArmorReduction() << std::endl
    << std::endl;
}

std::string     ClapTrap::appendName(void) {
    std::stringstream oss;
    oss << this->getName() << ": ";
    return oss.str();
}

void            ClapTrap::takeDamage(unsigned int amount) {
    if ((int)(this->_hitPoints - (amount - this->getArmorReduction())) < 0)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= (amount - this->getArmorReduction());
}

void            ClapTrap::beRepaired(unsigned int amount) {
    if ((int)(this->_hitPoints + amount) > 100)
        this->_hitPoints = 100;
    else
        this->_hitPoints += amount;
}

void            ClapTrap::looseEnergy(unsigned int amount) {
    if ((int)(this->_energyPoints - amount) < 0)
        this->_energyPoints = 0;
    else
        this->_energyPoints -= amount;
}

void            ClapTrap::meleeAttack(std::string const & target) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {   
        std::cout << "FR4G-TPt " << this->getName() << " attacks " << target << " at melee, causing " << this->getMeleeDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
    }
}

void            ClapTrap::rangedAttack(std::string const & target) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << "FR4G-TPt " << this->getName() << " attacks " << target << " at range, causing " << this->getRangedDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
    }
}
