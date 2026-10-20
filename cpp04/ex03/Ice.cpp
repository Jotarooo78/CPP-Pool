/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaunito <armaunito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:28:04 by armosnie          #+#    #+#             */
/*   Updated: 2026/02/08 15:45:05 by armaunito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &copy) : AMateria("ice") {
    
    (void)copy;
}

Ice & Ice::operator=(const Ice &copy) {

    (void)copy;
    return *this;
}

void Ice::use(ICharacter &target) {

    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const {

    return new Ice(*this);
}

