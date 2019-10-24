# include "Zombie.hpp"
# include "ZombieEvent.hpp"

std::string gen_random() {

    const char tab[] = "abcdefghijklmnopqrstuvwxyz";
    int         i = -1;
    std::string str(10, 0);

    while (++i < 10) {
        str[i] = tab[std::rand() % 27];
    }

    return str;

}

void    randomChump() {
    std::string _name = gen_random();
    Zombie      z(_name);
    ZombieEvent e;

    z.announce();
    e.setZombieType(&z, "archer");
    z.announce();
    return;
}

int     main(void) {
    ZombieEvent e;
    Zombie  *a;

    randomChump();

    a = e.newZombie(std::string("Christophe"));
    a->announce();
    e.setZombieType(a, "dancer");
    a->announce();
    delete a;

    return (0);
}