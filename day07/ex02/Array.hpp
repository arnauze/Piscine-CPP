#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class                   Array {

    public:
        Array(void) {
            this->n = 0;
            this->array = nullptr;
            return ;
        }

        ~Array(void) {
            delete [] this->array;
            return ;
        }

        Array(unsigned int n) {
            this->n = n;
            this->array = new T[n];
            return ;
        }

        Array(Array const & array) {
            *this = array;
            return ;
        }

		unsigned int		getSize(void) const {
			return this->n;
		}

        Array               &operator=(Array const & array) {
            this->n = array->n;
            this->array = array->array;
            return *this;
        }

        T                   operator[](unsigned int n) {
            if (n >= this->n)
                throw Array::outOfBound();
            else
                return this->array[n];
        }

        struct outOfBound : public std::exception {
            const char *what(void) const throw() {
                return "Out of bound";
            }
        };

    private:
        unsigned int    n;
        T               *array;

};

#endif
