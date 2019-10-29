#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class                               Character : public ICharacter {

    public:
        Character( std::string const & name );
        ~Character( void );
        Character( Character const & character );
        Character                   &operator=(Character const & character);

        std::string const &         getName() const;
        void                        equip(AMateria* m);
        void                        unequip(int idx);
        void                        use(int idx, ICharacter& target);

    private:
        Character(void);
        static int const            max_slots = 4;
        AMateria                    *slots[max_slots];
        int                         nb_equip;
        std::string                 name;

};

#endif