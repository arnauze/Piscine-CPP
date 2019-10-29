#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include "header.hpp"
# include "ISpaceMarine.hpp"

class        AssaultTerminator : public ISpaceMarine {

    public:
        AssaultTerminator(void);
        ~AssaultTerminator( void );
        AssaultTerminator( AssaultTerminator const & terminator );
        AssaultTerminator &operator=(AssaultTerminator const & terminator);

        ISpaceMarine                *clone(void) const;
        void                        battleCry(void) const;
        void                        rangedAttack(void) const;
        void                        meleeAttack(void) const;
};

#endif