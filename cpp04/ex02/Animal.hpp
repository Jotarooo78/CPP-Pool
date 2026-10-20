#ifndef ANIMAP_HPP
#define ANIMAP_HPP

#include <iostream>

class Animal {

    protected :
        std::string _type;

    public :
        Animal();
        virtual ~Animal();
        Animal(const Animal &AnimalCopy);
        Animal &operator=(const Animal &AnimalCopy);

        void setType(const std::string type);
        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif