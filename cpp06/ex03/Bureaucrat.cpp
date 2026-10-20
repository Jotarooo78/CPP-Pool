/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaunito <armaunito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:22:32 by armaunito         #+#    #+#             */
/*   Updated: 2026/02/05 18:29:38 by armaunito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {

   if (grade > 150)
      throw GradeTooLowException();
   else if (grade < 1)
      throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)  : _name(copy._name) {
   
      _grade = copy._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
   if (this != &copy) {
      _grade = copy._grade;
   }
   return *this;
}

int Bureaucrat::getGrade() const {

   return _grade;
}

const std::string Bureaucrat::getName() const {

   return _name;
}

void Bureaucrat::incrementGrade() {

   if (_grade - 1 < 1)
      throw Bureaucrat::GradeTooHighException();
   _grade--;
}

void Bureaucrat::decrementGrade() {

   if (_grade + 1 > 150)
      throw Bureaucrat::GradeTooLowException();
   _grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {

   std::cout << b.getName() << " Bureaucrat grade is " << b.getGrade() << "." << std::endl;
   return os;
}

void Bureaucrat::signForm(AForm &form) {
   
   try {
      form.beSigned(*this);
      std::cout << getName() << " signed " << form.getName() << std::endl;
   }
   catch(std::exception &e) {
      std::cout << getName() << " couldn't signed " << form.getName() << " because " << e.what() << std::endl;
   }
}

void Bureaucrat::executeForm(AForm const & form) const {

   try {
      form.execute(*this);
      std::cout << this->getName() << " executed " << form.getName() << std::endl;
   }
   catch (std::exception &e) {
      std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
   }
}