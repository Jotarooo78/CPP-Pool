/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaunito <armaunito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:12:24 by armosnie          #+#    #+#             */
/*   Updated: 2025/12/22 17:05:36 by armaunito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {

    std::cout << "Default Cat constructor has been called" << std::endl;
    _type = "Cat";
}

Cat::~Cat() {

    std::cout << "Cat Destructor has been called" << std::endl;
}

Cat::Cat(const Cat &CatCopy) : Animal(CatCopy) {

    std::cout << "Cat copy assignator has been called" << std::endl;
    _type = "Cat";
}

Cat &Cat::operator=(const Cat &CatCopy) {
    
    if (this != &CatCopy)
        Animal::operator=(CatCopy);
    return *this;
}

void Cat::makeSound() const {
    
    std::cout << "MIIIIIAAAAaaaaaaAAaaaAIIWDiwfiwioOOOOOUuuuwgUFDBWUYYuYUUUUUUUU" << std::endl;
}