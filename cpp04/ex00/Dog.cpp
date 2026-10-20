/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaunito <armaunito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:59:02 by armosnie          #+#    #+#             */
/*   Updated: 2025/12/22 17:05:59 by armaunito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {

    std::cout << "Default Dog constructor has been called" << std::endl;
    _type = "Dog";
}

Dog::~Dog() {

    std::cout << "Dog Destructor has been called" << std::endl;
}

Dog::Dog(const Dog &DogCopy) : Animal(DogCopy) {

    std::cout << "Dog copy assignator has been called" << std::endl;
    _type = "Dog";
}

Dog &Dog::operator=(const Dog &DogCopy) {
    
    if (this != &DogCopy)
        Animal::operator=(DogCopy);
    return *this;
}

void Dog::makeSound() const {
    
    std::cout << "BAAAAAAAAAAAAAARKKKKKKKKKKKDFNEWUFUEFBIBF" << std::endl;
}