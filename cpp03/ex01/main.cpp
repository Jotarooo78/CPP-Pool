/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:58:22 by armosnie          #+#    #+#             */
/*   Updated: 2025/12/17 15:42:32 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    ScavTrap jojo("Jojo");
    ClapTrap dio("Dio");

    jojo.attack("Dio");
    dio.takeDamage(30);
    dio.beRepaired(20);
    jojo.guardGate();
    return 0;
}