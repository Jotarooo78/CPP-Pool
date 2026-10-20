/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaunito <armaunito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:28:34 by armaunito         #+#    #+#             */
/*   Updated: 2026/02/12 15:44:25 by armaunito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &copy) {
   (void)copy;
}

Intern &Intern::operator=(const Intern &copy) {
   (void)copy;
   return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {

   AForm* (Intern::*creators[])(std::string) = {
      
      &Intern::createShrubbery,
      &Intern::createRobotomy,
      &Intern::createPardon 
   };

   std::string tab[] = {
      "shrubbery creation",
      "robotomy request",
      "presidential pardon"
   };

   for(int i = 0; i < 3; i++) {
      if (tab[i] == formName) {
         std::cout << "Intern creates the form : " << formName << std::endl;
         return (this->*creators[i])(target);
      }
   }
   std::cout << formName << "doesn't exist" << std::endl;
   return NULL;
}

AForm *Intern::createPardon(const std::string target) {
   return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomy(const std::string target) {
   return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubbery(const std::string target) {
   return new ShrubberyCreationForm(target);
}
