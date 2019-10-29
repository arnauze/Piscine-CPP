# include "Character.hpp"

Character::Character(void) { return ; }

Character::Character(std::string const & name) : _name(name), _ap(40), _weapon(NULL) {
    return ;
}

Character::~Character( void ) {
    return ;
}

Character::Character( Character const & character) {
    *this = character;
    return ;
}

Character           &Character::operator=(Character const & character) {
    this->setAp(character.getAp());
    this->setName(character.getName());
    this->equip(character._weapon);
    return *this;
}

void                Character::recoverAP(void) {
    this->setAp(this->getAp() + 10);
}

void                Character::equip(AWeapon * weapon) {
    this->_weapon = weapon;
    return ;
}

void                Character::attack(Enemy * enemy) {
    if (this->_weapon != NULL && this->getAp() >= 10) {
        std::cout << this->getName() <<  " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
        this->_weapon->attack();
        this->setAp(this->getAp() - this->_weapon->getApCost());
        enemy->setHp(enemy->getHp() - this->_weapon->getDamage());
        if (enemy->getHp() <= 0)
            delete enemy;
    }
}

std::string         Character::getName(void) const {
    return this->_name;
}

int                 Character::getAp(void) const {
    return this->_ap;
}

void                Character::setName(std::string const & name) {
    this->_name = name;
    return ;
}

void                Character::setAp(int ap) {
    if (ap > 40)
        this->_ap = 40;
    else
        this->_ap = ap;
    return ;
}

bool                 Character::hasWeapon(void) const {
    if (this->_weapon != NULL)
        return true;
    return false;
}

AWeapon             *Character::getWeapon(void) const {
    return this->_weapon;
}

std::ostream        &operator<<(std::ostream & os, Character const & character) {
    if (character.hasWeapon())
        os << character.getName() << " has " << character.getAp() << " AP and wields a " << character.getWeapon()->getName() << std::endl;
    else
        os << character.getName() << " has " << character.getAp() << " AP and is unarmed" << std::endl;
    return os;
}