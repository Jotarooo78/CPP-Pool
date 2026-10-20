/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:54:39 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/25 14:45:37 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "A zombie is invading the place..." << std::endl;
}

Zombie::~Zombie(){
    std::cout << "Zombie shot, RAS" << std::endl;
}

void Zombie::announce(int i){
    std::cout << _name << i << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string &name){
    _name = name;
}
