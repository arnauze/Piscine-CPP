#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class                           MateriaSource : public IMateriaSource {

    public:
        MateriaSource( void );
        ~MateriaSource( void );
        MateriaSource( MateriaSource const & source );

        MateriaSource           &operator=( MateriaSource const & source );
        void                    learnMateria(AMateria*);
        AMateria*               createMateria(std::string const & type);

    private:
        static int const        max_slots = 4;
        int                     nb_learned;
        AMateria                *slots[max_slots];
};

#endif