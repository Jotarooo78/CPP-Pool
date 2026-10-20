/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:56:43 by armosnie          #+#    #+#             */
/*   Updated: 2025/12/17 17:34:53 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() {
    
    std::cout << "DiamondTrap Default constructor has been called" << std::endl;
}

DiamondTrap::~DiamondTrap() {

    std::cout << "DiamondTrap Destructor has been called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &DiamondTrapCopy) {

    std::cout << "DiamondTrap Copy constructor has been called" << std::endl;
    this->_name = DiamondTrapCopy._name;
    this->_hitPoints = DiamondTrapCopy._hitPoints;
    this->_energyPoints = DiamondTrapCopy._energyPoints;
    this->_attackDamage = DiamondTrapCopy._attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &DiamondTrapCopy) {
    
    if (this != &DiamondTrapCopy)
    {        
        this->_name = DiamondTrapCopy._name;
        this->_hitPoints = DiamondTrapCopy._hitPoints;
        this->_energyPoints = DiamondTrapCopy._energyPoints;
        this->_attackDamage = DiamondTrapCopy._attackDamage;
    }
    return *this;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
    
    _name = name;
    std::cout << "DiamondTrap " << _name << " has been created" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
}

void DiamondTrap::whoAmI() {

    std::cout << "Code name - Diamond : I used to be called " << _name << " but i'm " << ClapTrap::_name << " too..." << std::endl;
}