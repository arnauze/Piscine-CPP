# include "Character.hpp"

Character::Character( void ) { return ; }

Character::Character( std::string const & name ) : nb_equip(0), name(name) {
    int i = -1;
    while (++i < this->max_slots) 
        this->slots[i] = NULL;
    return ;
}

Character::~Character( void ) {
    int         i = -1;
    while (++i < this->max_slots) {
        delete this->slots[i];
        this->slots[i] = NULL;
    }
    return ;
}

Character::Character( Character const & character ) {
    *this = character;
    return ;
}

Character                               &Character::operator=(Character const & character) {
    int                                 i = -1;

    while (++i < this->max_slots) {
        delete this->slots[i];
        this->slots[i] = character.slots[i]->clone();
    }
    this->nb_equip = character.nb_equip;
    this->name = character.getName();
    return *this;
}

std::string const &                     Character::getName() const {
    return this->name;
}

void                                    Character::equip(AMateria* m) {
    if (this->nb_equip < 4) {
        int                             i = -1;
        while (++i < this->max_slots) {
            if (!this->slots[i]) {
                this->slots[i] = m;
                break;
            }
        }
        this->nb_equip += 1 ;
    }
}

void                                    Character::unequip(int idx) {
    if (this->slots[idx]) {
        this->nb_equip -= 1;
        this->slots[idx] = NULL;
    }
}

void                                    Character::use(int idx, ICharacter& target) {
    if (this->slots[idx])
        this->slots[idx]->use(target);
}
