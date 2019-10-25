# include "Enemy.hpp"

Enemy::Enemy(void) { return ; }

Enemy::Enemy(int hp, std::string const & type) : _hp(hp), _type(type) { return ; }

Enemy::~Enemy(void) { return ; }

Enemy::Enemy(Enemy const & enemy) {
    *this = enemy;
    return ;
}

void        Enemy::takeDamage(int dmg) {
    if (dmg >= 0) {
        if ((this->getHp() - dmg) < 0)
            this->setHp(0);
        else
            this->setHp(this->getHp() - dmg);
    }
}

int         Enemy::getHp(void) const {
    return this->_hp;
}

std::string Enemy::getType(void) const {
    return this->_type;
}

void        Enemy::setType(std::string const & type) {
    this->_type = type;
    return ;
}

void        Enemy::setHp(int hp) {
    this->_type = hp;
    return ;
}

Enemy       &Enemy::operator=(Enemy const & enemy) {
    this->setType(enemy.getType());
    this->setHp(enemy.getHp());
    return *this;
}