#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {

    private :


    public :
        Cure();
        ~Cure();
        Cure(const Cure &copy);
        Cure & operator=(const Cure &copy);

        void use(ICharacter& target);
        AMateria* clone() const;
} ;

#endif