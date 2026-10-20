#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {

    private :

    public :
        Ice();
        ~Ice();
        Ice(const Ice &copy);
        Ice & operator=(const Ice &copy);

        void use(ICharacter& target);
        AMateria* clone() const;
} ;

#endif