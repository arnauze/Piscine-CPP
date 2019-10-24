#include "Contact.class.hpp"

    Contact::Contact(void) { return; }

    Contact::~Contact(void) { return; }

    std::string     Contact::getFirstName(void) const {
        return this->_first_name;
    }

    void            Contact::setFirstName(std::string str) {
        this->_first_name = str;
        return;
    }

    std::string     Contact::getLastName(void) const {
        return this->_last_name;
    }

    void            Contact::setLastName(std::string str) {
        this->_last_name = str;
        return;
    }

    std::string     Contact::getNickname(void) const {
        return this->_nickname;
    }

    void            Contact::setNickname(std::string str) {
        this->_nickname = str;
        return;
    }

    std::string     Contact::getLogin(void) const {
        return this->_login;
    }

    void            Contact::setLogin(std::string str) {
        this->_login = str;
        return;
    }

    std::string     Contact::getEmailAddress(void) const {
        return this->_email_address;
    }

    void            Contact::setEmailAddress(std::string str) {
        this->_email_address = str;
        return;
    }

    std::string     Contact::getPhoneNumber(void) const {
        return this->_phone_number;
    }

    void            Contact::setPhoneNumber(std::string str) {
        this->_phone_number = str;
        return;
    }

    std::string     Contact::getBirthdayDate(void) const {
        return this->_birthday_date;
    }

    void            Contact::setBirthdayDate(std::string str) {
        this->_birthday_date = str;
        return;
    }

    std::string     Contact::getFavoriteMeal(void) const {
        return this->_favorite_meal;
    }

    void            Contact::setFavoriteMeal(std::string str) {
        this->_favorite_meal = str;
        return;
    }

    std::string     Contact::getUnderwearColor(void) const {
        return this->_underwear_color;
    }

    void            Contact::setUnderwearColor(std::string str) {
        this->_underwear_color = str;
        return;
    }

    std::string     Contact::getDarkestSecret(void) const {
        return this->_darkest_secret;
    }

    void            Contact::setDarkestSecret(std::string str) {
        this->_darkest_secret = str;
        return;
    }


