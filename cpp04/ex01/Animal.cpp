/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:44:20 by armosnie          #+#    #+#             */
/*   Updated: 2025/12/18 14:14:53 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {

    std::cout << "Default Animal constructor has been called" << std::endl;
}

Animal::~Animal() {

    std::cout << "Animal Destructor has been called" << std::endl;
}

Animal::Animal(const Animal &AnimalCopy) {

    std::cout << "Animal copy assignator has been called" << std::endl;
    _type = AnimalCopy._type;
}

Animal &Animal::operator=(const Animal &AnimalCopy) {
    
    if (this != &AnimalCopy)
    {
        _type = AnimalCopy._type;
    }
    return *this;
}

std::string Animal::getType() const {

    return _type;
}

void Animal::setType(std::string type) {

    _type = type;
}

void Animal::makeSound() const {
    
    std::cout << "Goofy ahhh sound" << std::endl;
}