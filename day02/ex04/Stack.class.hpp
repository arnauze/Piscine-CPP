#ifndef STACK_CLASS_HPP
# define STACK_CLASS_HPP

# include <string>
# include <vector>

class                                   Stack {

    private:
        std::vector<std::string>        _elems;
 
    public:
        Stack( void );
        ~Stack( void );
        void                            add( std::string );
        std::string                     pop( void );
        std::string                     top( void );
        int                             size( void );
        bool                            isEmpty( void );

};

#endif