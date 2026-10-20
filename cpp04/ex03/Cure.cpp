/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaunito <armaunito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:36:47 by armosnie          #+#    #+#             */
/*   Updated: 2026/02/08 15:45:20 by armaunito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &copy) : AMateria("cure") {
    
    (void)copy;
}

Cure & Cure::operator=(const Cure &copy) {

    (void)copy;
    return *this;
}

void Cure::use(ICharacter &target) {

    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const {

    return new Cure(*this);
}