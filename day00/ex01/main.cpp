#include "header.hpp"
#include "Contact.class.hpp"
#include "Journal.class.hpp"

std::string     truncate(std::string original) {
    if (original.size() > 10) {
        original.resize(9);
        original.append(".");
        return original;
    } else {
        return original;
    }
}

int             main(void) {
    Journal     phonebook;
    Contact     contact;
    std::string input;

    while (!std::cin.eof()) {
        input = phonebook.getInput();
        if (input == "ADD") {
            phonebook.addContact();
        } else if (input == "SEARCH") {
            phonebook.showContacts();
        } else if (input == "EXIT") {
            return (0);
        }
    }
    return (1);
}