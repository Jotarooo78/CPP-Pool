/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:54:04 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/25 14:42:27 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string name = "Zombie";
    Zombie *horde = zombieHorde(10, name);
    for (int i = 0; i < 10; i++){
        horde[i].announce(i);
    }
    delete[] horde;
}