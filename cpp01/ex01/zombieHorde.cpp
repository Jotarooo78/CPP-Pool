/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:54:36 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/25 14:42:35 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name){
    
    Zombie *horde = new Zombie[n];
    for (int i = 0; i < n; i++){
        horde[i].setName(name);
    }
    return horde;
}