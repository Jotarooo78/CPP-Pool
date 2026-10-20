/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:51:39 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/26 16:32:32 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType) : _weaponType(weaponType) {}

Weapon::~Weapon() {}

std::string Weapon::getWeaponType() const {
    return _weaponType;
}

void Weapon::setWeaponType(std::string weaponType) {
    _weaponType = weaponType;
}