/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:26:01 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/27 11:34:30 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){
    _weapon = NULL;
}

HumanB::~HumanB() {
    
}

void HumanB::attack() {
    
    std::cout << _name << " is smashing a zombie head with his " << _weapon->getWeaponType() << std::endl;

}

void    HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
}