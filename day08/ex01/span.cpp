# include "span.hpp"

Span::Span(void) {
    return ;
}

Span::~Span(void) {
    return ;
}

Span::Span(unsigned int n) {
    this->array.reserve(n);
    this->n = n;
    return ;
}

Span::Span(Span const & span) {
    *this = span;
    return ;
}

Span        &Span::operator=(Span const & span) {
    this->n = span.n;
    this->array = span.array;
    return *this;
}

long        Span::shortestSpan(void) {
    if (this->array.size() < 2) {
        throw Span::nothing();
        return -1;
    } else {
        std::vector<int> newVector = this->array;
        std::sort(newVector.begin(), newVector.end());
        return static_cast<long>(static_cast<long>(newVector[1]) - static_cast<long>(newVector[0]));
    }
}

long        Span::longestSpan(void) {
    if (this->array.size() < 2)
        throw Span::nothing();
    return static_cast<long>((static_cast<long>(*(std::max_element(this->array.begin(), this->array.end()))) - static_cast<long>(*(std::min_element(this->array.begin(), this->array.end())))));
}

void        Span::addNumber(int n) {
    if (this->array.size() < this->n)
        this->array.push_back(n);
    else
        throw Span::full();
}
