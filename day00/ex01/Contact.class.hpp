#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include "header.hpp"

class                   Contact {

    public:
        Contact(void);
        ~Contact(void);
        std::string     getFirstName(void) const;
        void            setFirstName(std::string);
        std::string     getLastName(void) const;
        void            setLastName(std::string);
        std::string     getNickname(void) const;
        void            setNickname(std::string);
        std::string     getLogin(void) const;
        void            setLogin(std::string);
        std::string     getEmailAddress(void) const;
        void            setEmailAddress(std::string);
        std::string     getPhoneNumber(void) const;
        void            setPhoneNumber(std::string);
        std::string     getBirthdayDate(void) const;
        void            setBirthdayDate(std::string);
        std::string     getFavoriteMeal(void) const;
        void            setFavoriteMeal(std::string);
        std::string     getUnderwearColor(void) const;
        void            setUnderwearColor(std::string);
        std::string     getDarkestSecret(void) const;
        void            setDarkestSecret(std::string);

    private:
        std::string     _first_name;
        std::string     _last_name;
        std::string     _nickname;
        std::string     _login;
        std::string     _email_address;
        std::string     _phone_number;
        std::string     _birthday_date;
        std::string     _favorite_meal;
        std::string     _underwear_color;
        std::string     _darkest_secret;

};

#endif