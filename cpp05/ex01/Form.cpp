/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaunito <armaunito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:09:18 by armaunito         #+#    #+#             */
/*   Updated: 2026/02/05 19:13:33 by armaunito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int requiredSign, int requiredExec) : _name(name), _requiredSign(requiredSign), _requiredExec(requiredExec) {
   _signed = false;
}

Form::~Form() {}

Form::Form(const Form &copy) : _requiredSign(copy._requiredSign), _requiredExec(copy._requiredExec) {
   _signed = copy._signed;
}

Form &Form::operator=(const Form &copy) {

   if (this != &copy) {
      _signed = copy._signed;
   }
   return *this;
}

std::string Form::getName() const {
   return _name;
}

int Form::getRequiredExec() const {
   return _requiredExec;
}

int Form::getRequiredSign() const {
   return _requiredSign;
}

bool Form::getSigned() const {
   return _signed;
}

void Form::beSigned(const Bureaucrat &b) {
   
   if (b.getGrade() <= this->getRequiredSign())
      _signed = true;
   else {
      throw GradeTooLowException();
   }
}

std::ostream &operator<<(std::ostream &os, Form &form) {
   
   std::cout << form.getName() << (form.getSigned() ? " signed" : " not signed");
   return os;
}