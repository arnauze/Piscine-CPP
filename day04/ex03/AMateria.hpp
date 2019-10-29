#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "header.hpp"
# include "ICharacter.hpp"

class AMateria {
    protected:
        unsigned int                        xp;
        std::string const                   type;
    public:
        AMateria(std::string const & type);
        AMateria(void);
        virtual ~AMateria();
        AMateria                            &operator=(AMateria const & materia);

        std::string const &                 getType() const;
        unsigned int                        getXP() const;
        void                                setXP(unsigned int xp);

        virtual AMateria*                   clone() const = 0;
        virtual void                        use(ICharacter& target);
};

#endif