#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "header.hpp"
# include "Enemy.hpp"

class        RadScorpion : virtual public Enemy {

    public:
        RadScorpion(void);
        ~RadScorpion( void );
        RadScorpion( RadScorpion const & scorpion );
        RadScorpion &operator=(RadScorpion const & scorpion);

};

#endif