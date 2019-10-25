# include "ScavTrap.hpp"

typedef struct {
    void            (ScavTrap::*func)(std::string const & target);
}                   dispatch_t;

ScavTrap::ScavTrap(void) : ClapTrap("default") {
    srand(time(NULL));
    std::cout << "My name is " << this->_name << " how can I help?" << std::endl;
    return ;
}

ScavTrap::ScavTrap( std::string const & name ) : ClapTrap(name) {
    std::cout << "ScavTrap called " << name << " here to serve you." << std::endl;
    srand(time(NULL));
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 50;
    this->_maxEnergyPoints = 50;
    this->_level = 1;
    this->_meleeDamage = 20;
    this->_rangedDamage = 15;
    this->_armorReduction = 3;
    return ;
}

ScavTrap::~ScavTrap( void ) {
    std::cout << "ScavTrap " << this->getName() << " has died" << std::endl;
    return ;
}

ScavTrap::ScavTrap( ScavTrap const & frag ) : ClapTrap(frag) {
    *this = frag;
    std::cout << "ScavTrap called " << frag._name << " here to serve you." << std::endl;
    return ;
}

ScavTrap &      ScavTrap::operator=(ScavTrap const & frag) {
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

void            ScavTrap::rangedAttack(ScavTrap *ennemy) {
    if (this->_energyPoints < 25) {
        std::cout << this->appendName() << std::endl << "I don't have enough energy to do that." << std::endl;
    } else {    
        std::cout << "ScavTrap " << this->getName() << " attacks " << ennemy->getName() << " at range, causing " << this->getRangedDamage() - this->getArmorReduction() << " points of damage!" << std::endl;
        ennemy->takeDamage(this->getRangedDamage());
        this->looseEnergy(25);
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
