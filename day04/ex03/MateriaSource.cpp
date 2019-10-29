# include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : nb_learned(0) {
    int i = -1;
    while (++i < this->max_slots) 
        this->slots[i] = NULL;
    return ;
}

MateriaSource::~MateriaSource( void ) {
    int i = -1;
    if (this->nb_learned > 0) {
        while (++i < this->nb_learned) {
            delete this->slots[i];
            this->slots[i] = NULL;
        }
    }
    return ;
}

MateriaSource::MateriaSource( MateriaSource const & source) {
    *this = source;
    return ;
}

MateriaSource                       &MateriaSource::operator=( MateriaSource const & source) {
    int i = -1;
    while (++i < this->max_slots) {
        if (this->slots[i] != NULL)
            delete (this->slots[i]);
        this->slots[i] = source.slots[i]->clone();
    }
    this->nb_learned = source.nb_learned;
	return (*this);
}

void                                MateriaSource::learnMateria(AMateria* m) {
    int                             i = -1;

    if (this->nb_learned < 4) {
        while (++i < this->max_slots) {
            if (!this->slots[i]) {
                this->slots[i] = m;
                break ;
            }
        }
        this->nb_learned += 1;
    }
    return ;
}

AMateria*                           MateriaSource::createMateria(std::string const & type) {
    int i = -1;
    if (type == "ice" || type == "cure") {
        if (this->nb_learned > 0) {
            while (++i < this->max_slots) {
                if (this->slots[i])
                    if (this->slots[i]->getType() == type)
                        return this->slots[i]->clone();
            }
        }
    }
    return 0;
}
