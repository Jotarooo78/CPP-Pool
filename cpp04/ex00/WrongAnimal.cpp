/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:44:20 by armosnie          #+#    #+#             */
/*   Updated: 2025/12/18 14:14:53 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {

    std::cout << "Default WrongAnimal constructor has been called" << std::endl;
}

WrongAnimal::~WrongAnimal() {

    std::cout << "WrongAnimal Destructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimalCopy) {

    std::cout << "WrongAnimal copy assignator has been called" << std::endl;
    _type = WrongAnimalCopy._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimalCopy) {
    
    if (this != &WrongAnimalCopy)
    {
        _type = WrongAnimalCopy._type;
    }
    return *this;
}

std::string WrongAnimal::getType() const {

    return _type;
}

void WrongAnimal::setType(std::string type) {

    _type = type;
}

void WrongAnimal::makeSound() const {
    
    std::cout << "Goofy ahhh sound" << std::endl;
}