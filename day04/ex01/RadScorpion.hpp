#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "header.hpp"
# include "Enemy.hpp"

class        RadScorpion : public Enemy {

    public:
        RadScorpion(int hp);
        ~RadScorpion( void );
        RadScorpion( RadScorpion const & scorpion );
        RadScorpion &operator=(RadScorpion const & scorpion);

};

#endif