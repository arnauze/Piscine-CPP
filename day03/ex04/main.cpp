# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "NinjaTrap.hpp"
# include "SuperTrap.hpp"

int                     main(void) {

    std::cout << std::endl << "================CONSTRUCTING FRAGTRAPS================" << std::endl << std::endl;

    FragTrap            raymond("Raymond");
    FragTrap            arnaud("Arnaud");
    FragTrap            victor("Victor");

    std::cout << std::endl << "================CONSTRUCTING SCAVTRAPS================" << std::endl << std::endl;

    ScavTrap            maxence("Maxence");
    ScavTrap            antoine("Antoine");
    ScavTrap            jose("Jose");

    std::cout << std::endl << "================OUTPUT INFORMATIONS================" << std::endl << std::endl;

    raymond.getInfos();
    arnaud.getInfos();
    victor.getInfos();

    maxence.getInfos();
    antoine.getInfos();
    jose.getInfos();

    std::cout << std::endl << "================FRAGTAG RANGE ATTACK================" << std::endl << std::endl;

    raymond.rangedAttack(&arnaud);

    std::cout << std::endl << "================OUTPUT INFORMATIONS================" << std::endl << std::endl;

    raymond.getInfos();
    arnaud.getInfos();

    std::cout << std::endl << "================CALL FRAGTRAP'S SPECIAL FUNCTION 5 TIMES================" << std::endl << std::endl;

    arnaud.vaulthunter_dot_exe(&victor);
    arnaud.vaulthunter_dot_exe(&victor);
    arnaud.vaulthunter_dot_exe(&victor);
    arnaud.vaulthunter_dot_exe(&victor);

    std::cout << std::endl << "================WE RUN OUT OF ENERGY================" << std::endl << std::endl;

    arnaud.vaulthunter_dot_exe(&victor);

    std::cout << std::endl << "================GETTING INFORMATIONS================" << std::endl << std::endl;

    arnaud.getInfos();
    victor.getInfos();

    std::cout << std::endl << "================FRAGTAG MELEE ATTACKS================" << std::endl << std::endl;

    victor.meleeAttack(&raymond);
    victor.meleeAttack(&raymond);
    victor.meleeAttack(&raymond);
    victor.meleeAttack(&raymond);

    std::cout << std::endl << "================WE RUN OUT OF ENERGY================" << std::endl << std::endl;

    victor.meleeAttack(&raymond);

    std::cout << std::endl << "================GETTING INFORMATIONS================" << std::endl << std::endl;

    victor.getInfos();
    raymond.getInfos();

    std::cout << std::endl << "================SCAVTRAP SPECIAL ATTACKS================" << std::endl << std::endl;

    maxence.challengeNewcomer(antoine.getName());
    antoine.challengeNewcomer(jose.getName());
    jose.challengeNewcomer(maxence.getName());

    std::cout << std::endl << "================SCAVTRAP MELEE ATTACKS================" << std::endl << std::endl;

    maxence.meleeAttack(&antoine);
    antoine.meleeAttack(&maxence);

    std::cout << std::endl << "================CONSTRUCTING NINJATRAPS================" << std::endl << std::endl;

    NinjaTrap           etienne("Etienne");
    NinjaTrap           bastien("Bastien");
    NinjaTrap           benjamin("Benjamin");

    std::cout << std::endl << "================NINJATRAP SPECIAL ATTACKS================" << std::endl << std::endl;

    etienne.ninjaShoeBox(victor);
    etienne.ninjaShoeBox(maxence);
    etienne.ninjaShoeBox(etienne);

    std::cout << std::endl << "================CONSTRUCTING SUPERTRAP================" << std::endl << std::endl;

    SuperTrap           superman("Superman");

    std::cout << std::endl << "================SUPERTRAP CALLS NINJATRAP SPECIAL ATTACK================" << std::endl << std::endl;

    superman.ninjaShoeBox(victor);

    std::cout << std::endl << "================SUPERTRAP CALLS FRAGTAG SPECIAL ATTACK================" << std::endl << std::endl;

    superman.vaulthunter_dot_exe(&victor);

    std::cout << std::endl << "================DESTRUCTORS================" << std::endl << std::endl;

    return (0);
}