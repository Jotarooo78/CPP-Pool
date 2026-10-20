/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:24:31 by marvin            #+#    #+#             */
/*   Updated: 2025/12/22 15:24:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {

    std::cout << "Default Brain constructor has been called" << std::endl;
}

Brain::~Brain() {

    std::cout << "Brain Destructor has been called" << std::endl;
}

Brain::Brain(const Brain &BrainCopy) {

    std::cout << "Brain copy assignator has been called" << std::endl;
    if (this != &BrainCopy) {
      for (int i = 0; i < 100; i++)
         _ideas[i] = BrainCopy._ideas[i];
    }
}

Brain &Brain::operator=(const Brain &BrainCopy) {
    
   if (this != &BrainCopy) {
      for (int i = 0; i < 100; i++)
         _ideas[i] = BrainCopy._ideas[i];
   }
   return *this;
}

const std::string & Brain::getIdea(int index) const {

    if (index >= 0 && index < 100)
        return _ideas[index];
    return _ideas[0];
}

void Brain::setIdea(int index, const std::string& idea) {

    if (index >= 0 && index < 100)
        _ideas[index] = idea;
}