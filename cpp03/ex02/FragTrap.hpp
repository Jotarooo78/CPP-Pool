#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

    private :

    public :
        
        FragTrap();
        FragTrap(const FragTrap &FragTrapCopy);
        ~FragTrap();
        FragTrap &operator=(const FragTrap &FragTrapCopy);

        FragTrap(std::string name);
        void highFivesGuys(void);
    };

#endif