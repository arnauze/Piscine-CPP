#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>

template<typename T>
class                   MutantStack : public std::stack<T> {

    public:
        MutantStack(void) : std::stack<T>() {}
        ~MutantStack(void) {}

        MutantStack(MutantStack const & mutant) { (void)mutant; return; }
        MutantStack(std::stack<T> const & stack) { (void)stack; return; }

        using std::stack<T>::operator=;

        typedef typename            std::list<int>::iterator iterator;

        void                pop(void) {
            stack.pop_front();
            return ;
        }

        void                push(T value) {
            stack.push_front(value);
            return ;
        }

        T                   top(void) {
            return stack.front();
        }

        size_t              size(void) {
            return stack.size();
        }


        iterator            begin() {
            return stack.begin();
        }

        iterator            end() {
            return stack.end();
        }

    private:
        std::list<int>           stack;


};

#endif