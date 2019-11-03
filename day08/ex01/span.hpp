#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>

class               Span {

    public:
        Span(void);
        ~Span(void);
        Span(unsigned int n);
        Span(Span const & span);
        Span &operator=(Span const & span);

        long        shortestSpan(void);
        long        longestSpan(void);
        void        addNumber(int);

    private:
        unsigned int        n;
        std::vector<int>    array;

    struct full : public std::exception {
        virtual char const * what() const throw() {
            return "Array is full";
        }
    };

    struct nothing : public std::exception {
        virtual char const * what() const throw() {
            return "The array doesn't containe enough element to perfom the requested action";
        }
    };
};

#endif