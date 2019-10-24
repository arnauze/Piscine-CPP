#ifndef HUMAN_CPP
# define HUMAN_CPP

# include <string>
# include <iostream>

class Human {

    private:
        void meleeAttack(std::string const & target);
        void rangedAttack(std::string const & target);
        void intimidatingShout(std::string const & target);

    public:
        void action(std::string const & action_name, std::string const & target);
        Human( void );
        ~Human( void );

};

#endif