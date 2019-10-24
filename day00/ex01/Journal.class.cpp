#include "Journal.class.hpp"

    Journal::Journal(void) { return; }
    Journal::~Journal(void) { return; }

    std::string         Journal::getInput(void) const {
        std::string     input;
        std::cout << "Phonebook:" << std::endl;
        std::cout << "Available actions: [ADD, SEARCH, EXIT]" << std::endl;
        std::cin >> input;
        return input;
    }

    void                Journal::addContact() {
        std::string     tmp;
        Contact         contact;

        std::cout << "Adding a new contact:" << std::endl << std::endl;
        std::cout << "First name: ";
        std::cin >> tmp;
        if (std::cin.eof())
            exit(0);
        contact.setFirstName(tmp);
        std::cout << "Last name: ";
        std::cin >> tmp;
        if (std::cin.eof())
            exit(0);
        contact.setLastName(tmp);
        std::cout << "Nickname: ";
        std::cin >> tmp;
        if (std::cin.eof())
            exit(0);
        contact.setNickname(tmp);
        std::cout << "Login: ";
        std::cin >> tmp;
        if (std::cin.eof())
            exit(0);
        contact.setLogin(tmp);
        std::cout << "Email address: ";
        std::cin >> tmp;
        if (std::cin.eof())
            exit(0);
        contact.setEmailAddress(tmp);
        std::cout << "Phone number: ";
        std::cin >> tmp;
        if (std::cin.eof())
            exit(0);
        contact.setPhoneNumber(tmp);
        std::cout << "Birthday date: ";
        std::cin >> tmp;
        if (std::cin.eof())
            exit(0);
        contact.setBirthdayDate(tmp);
        std::cout << "Favorite meal: ";
        std::cin >> tmp;
        if (std::cin.eof())
            exit(0);
        contact.setFavoriteMeal(tmp);
        std::cout << "Underwear color: ";
        std::cin >> tmp;
        if (std::cin.eof())
            exit(0);
        contact.setUnderwearColor(tmp);
        std::cout << "Darkest secret: ";
        std::cin >> tmp;
        if (std::cin.eof())
            exit(0);
        contact.setDarkestSecret(tmp);
        std::cout << std::endl;

        if (this->_nbContacts < 8) {
            this->_contacts[this->_nbContacts] = contact;
            this->_nbContacts += 1;
        } else {
            this->_contacts[0] = contact;
        }
    }

    void                Journal::showContacts(void) const {
        int             i;
        std::string     input;

        input = "-1";
        i = -1;
        if (this->_nbContacts < 1) {
            std::cout << "There is no contacts in your phonebook for now. Start by adding one!" << std::endl;
            std::cout << std::endl;
        } else {
            std::cout << "|     index|first name| last name|  nickname|" << std::endl;
            while (++i < this->_nbContacts) {
                std::cout << "|" << std::right << std::setw(MAX_WIDTH) << i;
                std::cout << "|" << std::right << std::setw(MAX_WIDTH) << truncate(this->_contacts[i].getFirstName());
                std::cout << "|" << std::right << std::setw(MAX_WIDTH) << truncate(this->_contacts[i].getLastName());
                std::cout << "|" << std::right << std::setw(MAX_WIDTH) << truncate(this->_contacts[i].getNickname()) << "|" << std::endl << std::endl;
            }
            while (std::stoi(input) < 0 || std::stoi(input) >= this->_nbContacts) {
                std::cout << "Choose a user index to get more informations: ";
                std::cin >> input;
                if (std::cin.eof())
                    exit(0);
                std::cout << std::endl;
                Journal::searchContact(std::stoi(input));
            }
        }
    }

    void                 Journal::searchContact(int index) const {
        Contact         contact;

        if (index >= this->_nbContacts || index < 0) {
            std::cout << "There is no user for this index. Try again." << std::endl;
        } else {
            contact = this->_contacts[index];
            std::cout << "Contact at index " << index << ":" << std::endl;
            std::cout << "First name: " << contact.getFirstName() << std::endl;
            std::cout << "Last name: " << contact.getLastName() << std::endl;
            std::cout << "Nickname: " << contact.getNickname() << std::endl;
            std::cout << "Login: " << contact.getLogin() << std::endl;
            std::cout << "Email address: " << contact.getEmailAddress() << std::endl;
            std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
            std::cout << "Birthday date: " << contact.getBirthdayDate() << std::endl;
            std::cout << "Favorite meal: " << contact.getFavoriteMeal() << std::endl;
            std::cout << "Underwear color: " << contact.getUnderwearColor() << std::endl;
            std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl << std::endl;
        }
    }
