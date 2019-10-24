# include "FragTrap.hpp"

int                     main(void) {
    FragTrap            raymond("Raymond");
    FragTrap            arnaud("Arnaud");
    FragTrap            victor("Victor");

    raymond.getInfos();
    arnaud.getInfos();
    victor.getInfos();

    raymond.rangedAttack(&arnaud);

    raymond.getInfos();
    arnaud.getInfos();

    arnaud.vaulthunter_dot_exe(&victor);

    arnaud.getInfos();
    victor.getInfos();

    victor.meleeAttack(&raymond);

    victor.getInfos();
    raymond.getInfos();

    return (0);
}