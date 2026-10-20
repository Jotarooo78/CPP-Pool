/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:58:22 by armosnie          #+#    #+#             */
/*   Updated: 2025/12/17 16:46:09 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main() {

    FragTrap pucci("Pucci");
    ScavTrap jojo("Jojo");
    ClapTrap dio("Dio");

    pucci.attack("jojo");
    jojo.takeDamage(30);
    pucci.highFivesGuys();
    jojo.beRepaired(50);
    jojo.attack("Dio");
    dio.takeDamage(30);
    dio.beRepaired(20);
    jojo.guardGate();
    return 0;
}