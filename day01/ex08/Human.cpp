# include "Human.hpp"

Human::Human(void) { return ; }
Human::~Human(void) { return ; }

void Human::meleeAttack(std::string const & target) {
    std::cout << "* melee attack on " << target << " *" << std::endl;
    return ;
}

void Human::rangedAttack(std::string const & target) {
    std::cout << "* ranged attack on " << target << " *" << std::endl;
    return ;
}

void Human::intimidatingShout(std::string const & target) {
    std::cout << "* I'M GONNA KILL YOUUUUUU " << target << " *" << std::endl;
    return ;
}

typedef struct {
    std::string     name;
    void (Human::*func)(std::string const & target);
}       action_t;

void Human::action(std::string const & action_name, std::string const & target) {
    int         i = -1;

    action_t    actions[3] = {
        {"melee", &Human::meleeAttack},
        {"ranged", &Human::rangedAttack},
        {"shout", &Human::intimidatingShout}
    };

    while(++i < 3) {
        if (action_name == actions[i].name)
            (*this.*actions[i].func)(target);
    }
    
    return ;
}
