#ifndef PEON_HPP
# define PEON_HPP

# include "header.hpp"
# include "Victim.hpp"

class        Peon : public Victim {

    public:
        ~Peon( void );
        Peon( std::string const & name );
        Peon( Peon const & peon );
        Peon &operator=(Peon const & peon);
        void        getPolymorphed( void ) const;

    private:
        Peon(void);
};

std::ostream        &operator<<(std::ostream & out, Peon const & peon);

#endif