/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:10:40 by armosnie          #+#    #+#             */
/*   Updated: 2025/12/17 17:33:11 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
    
    std::cout << "FragTrap Default constructor has been called" << std::endl;
}

FragTrap::~FragTrap() {

    std::cout << "FragTrap Destructor has been called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &FragTrapCopy) {

    std::cout << "FragTrap Copy constructor has been called" << std::endl;
    this->_name = FragTrapCopy._name;
    this->_hitPoints = FragTrapCopy._hitPoints;
    this->_energyPoints = FragTrapCopy._energyPoints;
    this->_attackDamage = FragTrapCopy._attackDamage;
}

FragTrap &FragTrap::operator=(const FragTrap &FragTrapCopy) {
    
    if (this != &FragTrapCopy)
    {        
        this->_name = FragTrapCopy._name;
        this->_hitPoints = FragTrapCopy._hitPoints;
        this->_energyPoints = FragTrapCopy._energyPoints;
        this->_attackDamage = FragTrapCopy._attackDamage;
    }
    return *this;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    
    std::cout << "FragTrap " << _name << " has been created" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

void FragTrap::highFivesGuys() {

    std::cout << "FragTrap " << _name << " makes a high Fives with his slimes" << std::endl;
}