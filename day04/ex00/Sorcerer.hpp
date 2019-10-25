#ifndef SORCERER_HPP
# define SORCERER_HPP

# include "header.hpp"
# include "Victim.hpp"

class        Sorcerer {

    public:
        Sorcerer(std::string const & name, std::string const & type);
        ~Sorcerer( void );
        Sorcerer( Sorcerer const & sorcerer );
        Sorcerer &operator=(Sorcerer const & sorcerer);

        std::string             getName(void) const;
        std::string             getTitle(void) const;
        void                    setName(std:: string const &name);
        void                    setTitle(std:: string const &name);

        void                    polymorph(Victim const & victim) const;

    private:
        Sorcerer( void );
        std::string         _name;
        std::string         _title;
};

std::ostream & operator<<(std::ostream & out, Sorcerer const & sorcerer);

#endif