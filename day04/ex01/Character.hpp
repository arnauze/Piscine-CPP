#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "header.hpp"
# include "AWeapon.hpp"
# include "Enemy.hpp"

class                           Character {

    public:
        Character(std::string const & name);
        ~Character( void );
        Character( Character const & character );
        Character &operator=(Character const & character);

        void                    recoverAP(void);
        void                    attack(Enemy *);
        void                    equip(AWeapon *);

        std::string             getName(void) const;
        int                     getAp(void) const;
        void                    setName(std::string const & name);
        void                    setAp(int ap);
        bool                    hasWeapon(void) const;
        AWeapon                 *getWeapon(void) const;

    private:
        std::string             _name;
        int                     _ap;
        AWeapon                 *_weapon;
        Character(void);

};

std::ostream                    &operator<<(std::ostream & os, Character const & character);

#endif