#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

    public :
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat &WrongCatCopy);
        WrongCat &operator=(const WrongCat &WrongCatCopy);

        void makeSound() const;
};

#endif