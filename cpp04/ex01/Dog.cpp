/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:59:02 by armosnie          #+#    #+#             */
/*   Updated: 2026/01/13 13:52:19 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {

    std::cout << "Default Dog constructor has been called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::~Dog() {

    std::cout << "Dog Destructor has been called" << std::endl;
    delete _brain;
}

Dog::Dog(const Dog &DogCopy) : Animal(DogCopy) {

    std::cout << "Dog copy assignator has been called" << std::endl;
    _type = "Dog";
    _brain = new Brain(*DogCopy._brain);
}

Dog &Dog::operator=(const Dog &DogCopy) {
    
    if (this != &DogCopy) {
        Animal::operator=(DogCopy);
        delete _brain;
        _brain = new Brain(*DogCopy._brain);
    }
    return *this;
}

void Dog::makeSound() const {
    
    std::cout << "BAAAAAAAAAAAAAARKKKKKKKKKKKDFNEWUFUEFBIBF" << std::endl;
}

Brain *Dog::getBrain(void) const {
    
    return _brain;
}