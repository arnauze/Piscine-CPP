#include "Pony.class.hpp"

void    ponyOnTheHeap(void) {

    Pony*   maxence = new Pony("Maxence", "Red", "Female");

    delete maxence;

    return;

}

void    ponyOnTheStack(void) {
    Pony    maxence("Maxence", "Blue", "Female");
    return;
}

int     main(void) {

    ponyOnTheHeap();
    ponyOnTheStack();
    
    return (0);

}