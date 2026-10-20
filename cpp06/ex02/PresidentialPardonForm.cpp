/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:12:18 by armaunito         #+#    #+#             */
/*   Updated: 2026/03/03 13:31:25 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {

   if (this != &copy) {
      AForm::operator=(copy);
   }
   return *this;
}

std::string PresidentialPardonForm::getTarget() const {
   return _target;
}

void PresidentialPardonForm::executeAction() const {

   std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}