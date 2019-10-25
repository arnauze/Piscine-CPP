# include "AWeapon.hpp"

AWeapon::AWeapon(void) { return ; }

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _name(name), _apCost(apcost), _damage(damage) { return ; }

AWeapon::~AWeapon( void ) { return ; }

AWeapon::AWeapon( AWeapon const & weapon ) {
    *this = weapon;
    return ;
}

std::string     AWeapon::getName(void) const {
    return this->_name;
}

int             AWeapon::getApCost(void) const {
    return this->_apCost;
}

int             AWeapon::getDamage(void) const {
    return this->_damage;
}

void            AWeapon::setName(std::string const & name) {
    this->_name = name;
    return ;
}

void            AWeapon::setApCost(int const apCost) {
    this->_apCost = apCost;
    return ;
}

void            AWeapon::setDamage(int const damage) {
    this->_damage = damage;
    return ;
}

AWeapon         &AWeapon::operator=(AWeapon const & weapon) {
    this->setName(weapon.getName());
    this->setApCost(weapon.getApCost());
    this->setDamage(weapon.getDamage());
    return *this;
}