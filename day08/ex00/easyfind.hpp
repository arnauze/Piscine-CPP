#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <list>

template<typename T>
int         easyfind(T const & list, int i) {
    typename T::const_iterator     it = std::find(list.begin(), list.end(), i);

    if (it == list.end())
        throw std::exception();

    return *it;
}

#endif