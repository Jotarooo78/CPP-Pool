/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:06:10 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/24 16:51:58 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){
    
    std::cout << name << " is here" << std::endl;
}

Zombie::~Zombie(){

    std::cout << "destructer called" << std::endl;
}

void    Zombie::announce(){

    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}