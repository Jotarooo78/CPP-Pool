/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaunito <armaunito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:50:03 by armaunito         #+#    #+#             */
/*   Updated: 2026/02/05 15:16:08 by armaunito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

   try {
      Bureaucrat Bob("bob", 1);
      std::cout << Bob << std::endl;
      Bob.incrementGrade();
      std::cout << Bob << std::endl;
   }
   catch (std::exception &e) {
      std::cout << e.what() << std::endl;
   }
   
   try {
      Bureaucrat Carlos("Carlos", 2);
      std::cout << Carlos << std::endl;
   }
   catch (std::exception &e) {
      std::cout << e.what() << std::endl;
   }

   try {
      Bureaucrat Patrick("Patrick", 149);
      std::cout << Patrick << std::endl;
   }
   catch (std::exception &e) {
      std::cout << e.what() << std::endl;
   }
   
   try {
      Bureaucrat Sandy("Sandy", 151);
      std::cout << Sandy << std::endl;
      Sandy.decrementGrade();
      std::cout << Sandy << std::endl;
   }
   catch (std::exception &e) {
      std::cout << e.what() << std::endl;
   }

   return 0;
}