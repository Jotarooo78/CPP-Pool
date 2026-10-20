/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:09:20 by armosnie          #+#    #+#             */
/*   Updated: 2025/12/17 17:33:21 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    
    std::cout << "ScavTrap Default constructor has been called" << std::endl;
}

ScavTrap::~ScavTrap() {

    std::cout << "ScavTrap Destructor has been called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ScavTrapCopy) {

    std::cout << "ScavTrap Copy constructor has been called" << std::endl;
    this->_name = ScavTrapCopy._name;
    this->_hitPoints = ScavTrapCopy._hitPoints;
    this->_energyPoints = ScavTrapCopy._energyPoints;
    this->_attackDamage = ScavTrapCopy._attackDamage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ScavTrapCopy) {
    
    if (this != &ScavTrapCopy)
    {        
        this->_name = ScavTrapCopy._name;
        this->_hitPoints = ScavTrapCopy._hitPoints;
        this->_energyPoints = ScavTrapCopy._energyPoints;
        this->_attackDamage = ScavTrapCopy._attackDamage;
    }
    return *this;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    
    std::cout << "ScavTrap " << _name << " has been created" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

void ScavTrap::guardGate() {

    std::cout << "ScavTrap " << _name << " turns into guard mod..." << std::endl;
}