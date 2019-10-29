#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include "header.hpp"
# include "ISpaceMarine.hpp"

class        TacticalMarine : public ISpaceMarine {

    public:
        TacticalMarine();
        ~TacticalMarine( void );
        TacticalMarine( TacticalMarine const & marine );
        TacticalMarine &operator=(TacticalMarine const & marine);

        ISpaceMarine                *clone(void) const;
        void                        battleCry(void) const;
        void                        rangedAttack(void) const;
        void                        meleeAttack(void) const;
};

#endif