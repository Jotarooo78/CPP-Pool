#ifndef WRONGANIMAP_HPP
#define WRONGANIMAP_HPP

#include <iostream>

class WrongAnimal {

    protected :
        std::string _type;

    public :
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal &WrongAnimalCopy);
        WrongAnimal &operator=(const WrongAnimal &WrongAnimalCopy);

        void setType(const std::string type);
        std::string getType() const;
        void makeSound() const;
};

#endif