#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

    private :

        std::string _name;

    public :
        
        DiamondTrap();
        DiamondTrap(const DiamondTrap &DiamondTrapCopy);
        ~DiamondTrap();
        DiamondTrap &operator=(const DiamondTrap &DiamondTrapCopy);

        DiamondTrap(std::string name);
        void whoAmI();
};

#endif