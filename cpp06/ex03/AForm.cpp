/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaunito <armaunito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:09:18 by armaunito         #+#    #+#             */
/*   Updated: 2026/02/05 16:21:40 by armaunito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int requiredSign, int requiredExec) : _name(name), _requiredSign(requiredSign), _requiredExec(requiredExec) {
   _signed = false;
}

AForm::~AForm() {}

AForm::AForm(const AForm &copy) : _requiredSign(copy._requiredSign), _requiredExec(copy._requiredExec) {
   _signed = copy._signed;
}

AForm &AForm::operator=(const AForm &copy) {

   if (this != &copy) {
      _signed = copy._signed;
   }
   return *this;
}

std::string AForm::getName() const {
   return _name;
}

int AForm::getRequiredExec() const {
   return _requiredExec;
}

int AForm::getRequiredSign() const {
   return _requiredSign;
}

bool AForm::getSigned() const {
   return _signed;
}

void AForm::beSigned(const Bureaucrat &b) {
   
   if (b.getGrade() <= this->getRequiredSign()){
      _signed = true;
   }
   else {
      throw GradeTooLowException();
   }
}

std::ostream &operator<<(std::ostream &os, AForm &Aform) {
   
   std::cout << Aform.getName() << (Aform.getSigned() ? " signed" : " not signed");
   return os;
}

void AForm::execute(Bureaucrat const & executor) const {
   
   if (executor.getGrade() > this->getRequiredExec())
      throw (GradeTooLowException());
   else if (this->getSigned() != true)
      throw (FormNotSignedException());
   this->executeAction();
}