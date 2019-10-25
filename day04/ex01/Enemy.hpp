#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "header.hpp"

class        Enemy {

    public:
        Enemy(void);
        Enemy(int hp, std::string const & type);
        virtual ~Enemy( void );
        Enemy( Enemy const & enemy );
        Enemy &operator=(Enemy const & enemy);

        virtual void            takeDamage(int);
        virtual std::string     getType(void) const;
        int                     getHp(void) const;
        void                    setType(std::string const & type);
        void                    setHp(int hp);

    protected:
        std::string             _type;
        int                     _hp;
};

#endif