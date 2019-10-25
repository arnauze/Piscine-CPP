# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "NinjaTrap.hpp"

int                     main(void) {

    FragTrap            raymond("Raymond");
    FragTrap            arnaud("Arnaud");
    FragTrap            victor("Victor");

    ScavTrap            maxence("Maxence");
    ScavTrap            antoine("Antoine");
    ScavTrap            jose("Jose");

    raymond.getInfos();
    arnaud.getInfos();
    victor.getInfos();

    maxence.getInfos();
    antoine.getInfos();
    jose.getInfos();

    raymond.rangedAttack(&arnaud);

    raymond.getInfos();
    arnaud.getInfos();

    arnaud.vaulthunter_dot_exe(&victor);
    arnaud.vaulthunter_dot_exe(&victor);
    arnaud.vaulthunter_dot_exe(&victor);
    arnaud.vaulthunter_dot_exe(&victor);
    arnaud.vaulthunter_dot_exe(&victor);

    arnaud.getInfos();
    victor.getInfos();

    victor.meleeAttack(&raymond);
    victor.meleeAttack(&raymond);
    victor.meleeAttack(&raymond);
    victor.meleeAttack(&raymond);
    victor.meleeAttack(&raymond);

    victor.getInfos();
    raymond.getInfos();

    maxence.challengeNewcomer(antoine.getName());
    antoine.challengeNewcomer(jose.getName());
    jose.challengeNewcomer(maxence.getName());
    maxence.meleeAttack(&antoine);
    antoine.meleeAttack(&maxence);

    NinjaTrap           etienne("Etienne");
    NinjaTrap           bastien("Bastien");
    NinjaTrap           benjamin("Benjamin");

    etienne.ninjaShoeBox(victor);
    etienne.ninjaShoeBox(maxence);
    etienne.ninjaShoeBox(etienne);

    return (0);
}