#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {

    public :
        Cat();
        ~Cat();
        Cat(const Cat &CatCopy);
        Cat &operator=(const Cat &CatCopy);

        void makeSound() const;
};

#endif