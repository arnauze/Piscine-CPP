#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include "header.hpp"

class        AWeapon {

    public:
        AWeapon(void);
        AWeapon(std::string const & name, int apcost, int damage);
        virtual ~AWeapon( void );
        AWeapon( AWeapon const & weapon );
        AWeapon &operator=(AWeapon const & weapon);

        virtual void            attack() const = 0;

        int                     getApCost(void) const;
        int                     getDamage(void) const;
        std::string             getName(void) const;
        void                    setApCost(int const apCost);
        void                    setName(std::string const & name);
        void                    setDamage(int const damage);

    private:
        std::string             _name;
        int                     _apCost;
        int                     _damage;

};

#endif