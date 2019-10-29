# include "Squad.hpp"

Squad::Squad(void) : _squad(NULL), _count(0) { return ; }

Squad::~Squad( void ) {
    t_list          *current;
    t_list          *tmp;

    current = this->_squad;
    if (current) {
        while (current) {
            tmp = current->next;
            delete current->marine;
            delete current;
            current = tmp;
        }
    }
    this->_squad = NULL;
    return ;
}

Squad::Squad( Squad const & squad ) {
    *this = squad;
    return ;
}

Squad                   &Squad::operator=(Squad const & squad) {
    t_list          *current;
    t_list          *tmp;

    if (this->_squad) {
        current = this->_squad;
        while (current) {
            tmp = current->next;
            delete current->marine;
            delete current;
            current = tmp;
        }
    }
    if (!squad._squad)
        this->_squad = NULL;
    else {
        current = squad._squad;
        while (current) {
            this->push(current->marine);
            current = current->next;
        }
    }
    this->setCount(squad.getCount());
    return *this;
}

int                     Squad::getCount(void) const {
    return this->_count;
}

void                    Squad::setCount(int count) {
    this->_count = count;
    return ;
}

ISpaceMarine            *Squad::getUnit(int N) const {
    t_list              *current;
    int                 i = -1;
    int                 total = this->getCount();

    if (N >= total)
        return NULL;
    current = this->_squad;
    while (current && ++i < N)
        current = current->next;
    return current->marine;
}

int                     Squad::push(ISpaceMarine * marine) {
    t_list      *newUnit = new t_list;

    newUnit->marine = marine;
    newUnit->next = NULL;
    if (this->_squad) {
        t_list      *current;
        current = this->_squad;
        while (current->next)
            current = current->next;
        current->next = newUnit;
    } else
        this->_squad = newUnit;
    this->setCount(this->getCount() + 1);
    return this->getCount();
}