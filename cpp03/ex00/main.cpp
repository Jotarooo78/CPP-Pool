/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:58:22 by armosnie          #+#    #+#             */
/*   Updated: 2025/12/18 11:20:52 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

    ClapTrap jojo("Jojo");
    ClapTrap dio("Dio");

    jojo.attack("Dio");
    dio.takeDamage(5);
    dio.beRepaired(10);
    return 0;
}