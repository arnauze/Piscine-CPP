# include "ScavTrap.hpp"

typedef struct {
    void            (ScavTrap::*func)(std::string const & target);
}                   dispatch_t;

ScavTrap::ScavTrap(void) : _name("default") {
    srand(time(NULL));
    std::cout << "My name is " << this->_name << " how can I help?" << std::endl;
    return ;
}

ScavTrap::ScavTrap( std::string const & name ) : _name(name) {
    std::cout << "ScavTrap called " << name << " here to serve you." << std::endl;
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

ScavTrap::~ScavTrap( void ) {
    std::cout << "ScavTrap " << this->getName() << " has died" << std::endl;
    return ;
}

ScavTrap::ScavTrap( ScavTrap const & frag ) {
    *this = frag;
    std::cout << "ScavTrap called " << frag._name << " here to serve you." << std::endl;
    return ;
}

ScavTrap &      ScavTrap::operator=(ScavTrap const & frag) {
    std::cout << "ScavTrap called " << frag._name << " here to serve you." << std::endl;
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

void            ScavTrap::rangedAttack(std::string const & target) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << " at range, causing " << this->getRangedDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
    }
}

void            ScavTrap::rangedAttack(ScavTrap *ennemy) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << "ScavTrap " << this->getName() << " attacks " << ennemy->getName() << " at range, causing " << this->getRangedDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
        ennemy->takeDamage(this->getRangedDamage());
        this->looseEnergy(25);
    }
}

void            ScavTrap::meleeAttack(std::string const & target) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {   
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << " at melee, causing " << this->getMeleeDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
    }
}

void            ScavTrap::meleeAttack(ScavTrap  *ennemy) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << "ScavTrap " << this->getName() << " attacks " << ennemy->getName() << " at melee, causing " << this->getMeleeDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
        ennemy->takeDamage(this->getMeleeDamage());
        this->looseEnergy(25);
    }
}

std::string     ScavTrap::appendName(void) {
    std::stringstream oss;
    oss << this->getName() << ": ";
    return oss.str();
}

void            ScavTrap::takeDamage(unsigned int amount) {
    if ((int)(this->_hitPoints - (amount - this->getArmorReduction())) < 0)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= (amount - this->getArmorReduction());
}

void            ScavTrap::beRepaired(unsigned int amount) {
    if ((int)(this->_hitPoints + amount) > 100)
        this->_hitPoints = 100;
    else
        this->_hitPoints += amount;
}

void            ScavTrap::looseEnergy(unsigned int amount) {
    if ((int)(this->_energyPoints - amount) < 0)
        this->_energyPoints = 0;
    else
        this->_energyPoints -= amount;
}

void            ScavTrap::firstChallenge(std::string const & target) {
    std::string input;

    std::cout << std::endl << "Welcome " << target << " here is my challenge:" << std::endl << "The more you take, the more you leave behind. What am I?" << std::endl;
    std::cin >> input;

    if (input == "Footsteps" || input == "footsteps")
        std::cout << "Congratulations !" << std::endl;
    else
        std::cout << "Wrong! The answer is footsteps." << std::endl;
}

void            ScavTrap::secondChallenge(std::string const & target) {
    std::string input;

    std::cout << std::endl << "Welcome " << target << " here is my challenge:" << std::endl << "What room do ghosts avoid?" << std::endl;
    std::cin >> input;
    
    if (input == "Livingroom" || input == "livingroom")
        std::cout << "Congratulations !" << std::endl;
    else
        std::cout << "Wrong! The answer is living room." << std::endl;
}

void            ScavTrap::thirdChallenge(std::string const & target) {
    std::string input;

    std::cout << std::endl << "Welcome " << target << " here is my challenge:" << std::endl << "What belongs to you, but other people use it more than you?" << std::endl;
    std::cin >> input;
    
    if (input == "Name" || input == "name")
        std::cout << "Congratulations !" << std::endl;
    else
        std::cout << "Wrong! The answer is your name." << std::endl;
}

void            ScavTrap::fourthChallenge(std::string const & target) {
    std::string input;

    std::cout << std::endl << "Welcome " << target << " here is my challenge:" << std::endl << "Re-arrange the letters, O O U S W T D N E J R, to spell just one word. What is it?" << std::endl;
    std::cin >> input;
    
    if (input == "justoneword" || input == "justoneword")
        std::cout << "Congratulations !" << std::endl;
    else
        std::cout << "Wrong! The answer was 'just one word'." << std::endl;
}

void            ScavTrap::fifthChallenge(std::string const & target) {
    std::string input;

    std::cout << std::endl << "Welcome " << target << " here is my challenge:" << std::endl << "What is more useful when it is broken?" << std::endl;
    std::cin >> input;
    
    if (input == "Eggs" || input == "eggs")
        std::cout << "Congratulations !" << std::endl;
    else
        std::cout << "Wrong! The answer was eggs." << std::endl;
}

void            ScavTrap::challengeNewcomer(std::string const & target) {
    dispatch_t  dispatchTable[5] = {
        {&ScavTrap::firstChallenge},
        {&ScavTrap::secondChallenge},
        {&ScavTrap::thirdChallenge},
        {&ScavTrap::fourthChallenge},
        {&ScavTrap::fifthChallenge},
    };

    int x = rand() % 5;
    (this->*dispatchTable[x].func)(target);    
    return ;
}

int             ScavTrap::getHitPoints(void) {
    return this->_hitPoints;
}

int             ScavTrap::getMaxHitPoints(void) {
    return this->_maxHitPoints;
}

int             ScavTrap::getEnergyPoints(void) {
    return this->_energyPoints;
}

int             ScavTrap::getMaxEnergyPoints(void) {
    return this->_maxEnergyPoints;
}

int             ScavTrap::getLevel(void) {
    return this->_level;
}

std::string     ScavTrap::getName(void) {
    return this->_name;
}

int             ScavTrap::getMeleeDamage(void) {
    return this->_meleeDamage;
}

int             ScavTrap::getRangedDamage(void) {
    return this->_rangedDamage;
}

int             ScavTrap::getArmorReduction(void) {
    return this->_armorReduction;
}

void            ScavTrap::getInfos(void) {
    std::cout << std::endl
    << "ScavTrap called " << this->getName() << std::endl
    << "HP: " << this->getHitPoints() << std::endl
    << "Energy: " << this->getEnergyPoints() << std::endl
    << "Level: " << this->getLevel() << std::endl
    << "Armor reduction: " << this->getArmorReduction() << std::endl
    << std::endl;
}