#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

    private :
        Brain *_brain;
    public :
        Cat();
        ~Cat();
        Cat(const Cat &CatCopy);
        Cat &operator=(const Cat &CatCopy);

        void makeSound() const;
        Brain *getBrain() const;
};

#endif