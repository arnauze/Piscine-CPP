#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

typedef struct                              s_list {

    struct s_list                           *next;
    ISpaceMarine                            *marine;
}                                           t_list;

class                                       Squad : public ISquad {
    public:
        Squad(void);
        ~Squad( void );
        Squad( Squad const & squad );
        Squad &operator=(Squad const & squad);

        int                                 getCount(void) const;
        void                                setCount(int);
        ISpaceMarine                        *getUnit(int N) const;
        int                                 push(ISpaceMarine *);
    
    private:
        t_list                              *_squad;
        int                                 _count;

};

#endif