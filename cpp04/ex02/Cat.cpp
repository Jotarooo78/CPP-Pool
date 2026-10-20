/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaunito <armaunito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:12:24 by armosnie          #+#    #+#             */
/*   Updated: 2025/12/22 17:13:38 by armaunito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {

    std::cout << "Default Cat constructor has been called" << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::~Cat() {

    std::cout << "Cat Destructor has been called" << std::endl;
    delete _brain;
}

Cat::Cat(const Cat &CatCopy) : Animal(CatCopy) {

    std::cout << "Cat copy assignator has been called" << std::endl;
    _type = "Cat";
    _brain = new Brain(*CatCopy._brain);
}

Cat &Cat::operator=(const Cat &CatCopy) {
    
    if (this != &CatCopy) {
        Animal::operator=(CatCopy);
        delete _brain;
        _brain = new Brain(*CatCopy._brain);
    }
    return *this;
}

void Cat::makeSound() const {
    
    std::cout << "MIIIIIAAAAaaaaaaAAaaaAIIWDiwfiwioOOOOOUuuuwgUFDBWUYYuYUUUUUUUU" << std::endl;
}

Brain *Cat::getBrain(void) const {
    
    return _brain;
}