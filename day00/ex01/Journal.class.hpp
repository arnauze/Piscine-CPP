#ifndef JOURNAL_CLASS_HPP
# define JOURNAL_CLASS_HPP

# include "header.hpp"
# include "Contact.class.hpp"

class Journal {

    public:
        Journal(void);
        ~Journal(void);
        std::string         getInput(void) const;
        void                addContact(void);
        void                showContacts(void) const;
        void                searchContact(int) const;

    private:
        Contact             _contacts[MAX_CONTACTS];
        int                 _nbContacts;

};

#endif