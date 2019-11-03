 # include <cstdlib>
 # include <string>
 # include <iostream>

class           Base { public: virtual ~Base(void) {} };
class           A : public Base { ~A() {} };
class           B : public Base { ~B() {} };
class           C : public Base { ~C() {} };

Base            *generate(void) {
    int         x = rand() % 3;
    if (x == 0)
        return new A();
    else if (x == 1)
        return new B();
    else if (x == 2)
        return new C();
    else
        return nullptr;
}

void            identify_from_pointer(Base *p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void            identify_from_reference(Base &p) {


    if(dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if( dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;

}

int             main(void) {
    Base        *b;

    b = generate();
    identify_from_pointer(b);
    identify_from_reference(*b);
    srand(time(nullptr));
    delete b;
    return (1);
}
