/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:58:35 by armaunito         #+#    #+#             */
/*   Updated: 2026/03/03 13:32:16 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {

   if (this != &copy) {
      AForm::operator=(copy);
   }
   return *this;
}

std::string RobotomyRequestForm::getTarget() const {
   return _target;
}

void RobotomyRequestForm::executeAction() const {

   std::cout << "BrrrZzzzzzzZzzzzrrrrrRRRrrrrrrr *drilling noises*" << std::endl;
   if (rand() % 2 == 0)
      std::cout << _target << " has been robotomisized" << std::endl;
   else
      std::cout << _target << " : Nothing... happened to me ?" << std::endl;
}