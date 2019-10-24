#ifndef HUMAN_CPP
# define HUMAN_CPP

# include "Brain.hpp"

class               Human {

    public:
        Human( void );
        ~Human( void );
        std::string     identify( void );
        Brain &           getBrain( void );

    private:
        Brain      _brain;

};

#endif