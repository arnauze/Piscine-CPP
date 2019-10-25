# include "SuperTrap.hpp"

SuperTrap::SuperTrap( void ) : ClapTrap(), FragTrap(), NinjaTrap() {
    std::cout << "And a new king (" << "default" << ") was born." << std::endl;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_maxHitPoints = FragTrap::_maxHitPoints;
    this->_energyPoints = NinjaTrap::_energyPoints;
    this->_maxEnergyPoints = NinjaTrap::_maxEnergyPoints;
    this->_level = 1;
    this->_meleeDamage = NinjaTrap::_meleeDamage;
    this->_rangedDamage = FragTrap::_rangedDamage;
    this->_armorReduction = FragTrap::_armorReduction;
    this->_name = "default";
    return ;
}

SuperTrap::SuperTrap(std::string const & name) : ClapTrap(name), FragTrap(name), NinjaTrap(name) {
    std::cout << "And a new king (" << name << ") was born." << std::endl;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_maxHitPoints = FragTrap::_maxHitPoints;
    this->_energyPoints = NinjaTrap::_energyPoints;
    this->_maxEnergyPoints = NinjaTrap::_maxEnergyPoints;
    this->_level = 1;
    this->_meleeDamage = NinjaTrap::_meleeDamage;
    this->_rangedDamage = FragTrap::_rangedDamage;
    this->_armorReduction = FragTrap::_armorReduction;
    return ;
}

SuperTrap::~SuperTrap( void ) {
    std::cout << "How could you betray me ?" << std::endl;
    return ;
}

SuperTrap::SuperTrap( SuperTrap const & s ) {
    *this = s;
    return ;
}

SuperTrap        &SuperTrap::operator=(SuperTrap const & s ) {
    this->_hitPoints = s._hitPoints;
    this->_maxHitPoints = s._maxHitPoints;
    this->_energyPoints = s._energyPoints;
    this->_maxEnergyPoints = s._maxEnergyPoints;
    this->_level = 1;
    this->_meleeDamage = s._meleeDamage;
    this->_rangedDamage = s._rangedDamage;
    this->_armorReduction = s._armorReduction;
    this->_name = s._name;
    return *this;
}

void            SuperTrap::meleeAttack(std::string const & target) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {   
        std::cout << "SuperTrap " << this->getName() << " attacks " << target << " at melee, causing " << this->getMeleeDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
    }
}

void            SuperTrap::rangedAttack(std::string const & target) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << "SuperTrap " << this->getName() << " attacks " << target << " at range, causing " << this->getRangedDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
    }
}

std::string     SuperTrap::getType(void) const {
    return std::string("SuperTrap");
}
