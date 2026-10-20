/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:18:44 by armosnie          #+#    #+#             */
/*   Updated: 2026/01/26 17:11:50 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default") {

    for (int i = 0; i < 4; i++) {
    _inventory[i] = NULL;
    }
}

Character::~Character() {

    for (int i = 0; i < 4; i++) {
        if (_inventory[i] != NULL)
            delete _inventory[i];
    }
}

Character::Character(const Character &copy) {

    _name = copy._name;
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
        if (copy._inventory[i] != NULL)
            _inventory[i] = copy._inventory[i]->clone();
    }
}

Character & Character::operator=(const Character &copy) {
    
    if (this != &copy)
    {
            _name = copy._name;
        
        for (int i = 0; i < 4; i++) {
            if (_inventory[i] != NULL) {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            if (copy._inventory[i] != NULL)
                _inventory[i] = copy._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return *this;       
}

Character::Character(std::string const &name) : _name(name) {

    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

std::string const & Character::getName() const {
    
    return this->_name;
}

void Character::equip(AMateria *m) {

    if (m == NULL)
        return ;
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m;
            return ;
        }
    }
}

void    Character::unequip(int idx) {

    if (idx < 0 || idx > 3)
        return ;
    if (_inventory[idx] != NULL) {
        _inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target) {

    if (idx < 0 || idx > 3)
        return ;
    if (_inventory[idx] != NULL) {
        _inventory[idx]->use(target);
    }
}
