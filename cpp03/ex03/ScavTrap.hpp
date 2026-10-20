#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

    private :

    public :

        ScavTrap();
        ~ScavTrap();
        ScavTrap(const ScavTrap &ScavTrapCopy);
        ScavTrap &operator=(const ScavTrap &ScavTrapCopy);
        
        ScavTrap(std::string name);
        void guardGate();
};

#endif