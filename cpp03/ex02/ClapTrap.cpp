/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:47:25 by armosnie          #+#    #+#             */
/*   Updated: 2025/12/17 17:33:48 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {

    std::cout << "ClapTrap Default constructor has been called" << std::endl;
}

ClapTrap::~ClapTrap() {
    
    std::cout << "ClapTrap Destructor has been called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ClapTrapCopy) {
    
    if (this != &ClapTrapCopy)
    {        
        this->_name = ClapTrapCopy._name;
        this->_hitPoints = ClapTrapCopy._hitPoints;
        this->_energyPoints = ClapTrapCopy._energyPoints;
        this->_attackDamage = ClapTrapCopy._attackDamage;
    }
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap &ClapTrapCopy) {
    
    std::cout << "ClapTrap Copy constructor has been called" << std::endl;
    this->_name = ClapTrapCopy._name;
    this->_hitPoints = ClapTrapCopy._hitPoints;
    this->_energyPoints = ClapTrapCopy._energyPoints;
    this->_attackDamage = ClapTrapCopy._attackDamage;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

    std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    
    if (_hitPoints <= 0) {
        std::cout << _name << " is dead" << std::endl;
        return ;
    }
    std::cout << _name << " has received " << amount << " damage" << std::endl;
    _hitPoints -= amount;
}

void ClapTrap::attack(const std::string& target) {

    if (_hitPoints <= 0 || _energyPoints <= 0)
        std::cout << "no energy left from " << _name << std::endl;
    else {
        std::cout << _name << " attacks " << target << ", inflincting " << _attackDamage << " damages !!!" << std::endl;
        _energyPoints -= 1;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    
    if (_energyPoints <= 0) {
        std::cout << _name << ":" << _hitPoints << std::endl;
        std::cout << "no energy left from " << _name << std::endl;
    }
    if (_hitPoints <= 0)
        std::cout << _name << " is dead" << std::endl;
    else {
        std::cout << _name << " has been healed " << amount << " hit points" << std::endl;
        _energyPoints -= 1;
        _hitPoints += amount;
    }
        
}