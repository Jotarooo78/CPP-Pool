/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:38:46 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/24 16:46:18 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    
    Zombie *heapZombie = newZombie("heapZombie");
    heapZombie->announce();
    delete heapZombie;
    randomChump("stackZombie");
    return (0);
}