#include <string>
#include <cstdlib>
#include <iostream>
#include <random>
#include <climits>

struct          Data {
    std::string         s1;
    int                 n;
    std::string         s2;
};

void                    *serialize(void) {
    Data *newData = new Data;
	char s1[9];
	char s2[9];
	std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 60);	
	std::uniform_int_distribution<std::mt19937::result_type> dist2(INT_MIN, INT_MAX);
	
	static const char alphanumeric[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	for (int i = 0;i < 8;i++)
	{
		s1[i] = alphanumeric[dist(rng)];
		s2[i] = alphanumeric[dist(rng)];
	}
	s1[8] = '\0';
	s2[8] = '\0';
	newData->n = dist2(rng);	
	newData->s1 = (s1);
	newData->s2 = (s2);

	std::cout << "Original s1: " << newData->s1 << std::endl;
	std::cout << "Original  n: " << newData->n  << std::endl;
	std::cout << "Original s2: " << newData->s2 << std::endl;

	return (reinterpret_cast<void*>(newData));
}

Data                    *deserialize(void *raw) {
    return reinterpret_cast<Data *>(raw);
}

int                     main(void) {
    void                *ptr;
    Data                *dataptr;

    ptr = serialize();
    dataptr = deserialize(ptr);

    std::cout << "Final s1: " << dataptr->s1 << std::endl;
	std::cout << "Final  n: " << dataptr->n  << std::endl;
	std::cout << "Final s2: " << dataptr->s2 << std::endl;

    return (0);
}