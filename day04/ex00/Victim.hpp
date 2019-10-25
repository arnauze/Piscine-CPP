#ifndef VICTIM_HPP
# define VICTIM_HPP

# include "header.hpp"

class        Victim {

    public:
        ~Victim( void );
        Victim( std::string const & name );
        Victim( Victim const & victim );
        Victim &operator=(Victim const & victim);
        virtual void        getPolymorphed( void ) const;

        std::string         getName(void) const;
        void                setName(std::string const & name);

    protected:
        std::string         _name;
        Victim( void );

};

std::ostream        &operator<<(std::ostream & out, Victim const & in);

#endif