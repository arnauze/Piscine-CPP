#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class                   Zombie {

    private:
        std::string     _name;
        std::string     _type;

    public:
        void            announce(void) const;
        void            setType(std::string t);
        Zombie( std::string _n );
        ~Zombie( void );

};

#endif