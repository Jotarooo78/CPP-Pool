/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:55:12 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/27 11:35:25 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon club = Weapon("club");
    HumanA Rick = HumanA("Rick", club);
    Rick.attack();

    HumanB Daryl = HumanB("Daryl");
    club.setWeaponType("club with nails");
    Daryl.setWeapon(club);
    Daryl.attack();
    return 0;
}