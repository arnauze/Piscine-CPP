#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "header.hpp"
# include "Enemy.hpp"

class        SuperMutant : public virtual Enemy {

    public:
        SuperMutant(int hp);
        ~SuperMutant( void );
        SuperMutant( SuperMutant const & mutant );
        SuperMutant &operator=(SuperMutant const & mutant);

        void        takeDamage(int);

};

#endif