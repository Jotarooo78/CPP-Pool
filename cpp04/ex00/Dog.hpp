#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {

    public :
        Dog();
        ~Dog();
        Dog(const Dog &DogCopy);
        Dog &operator=(const Dog &DogCopy);

        void makeSound() const;
};

#endif