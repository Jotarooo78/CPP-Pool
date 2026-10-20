/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:26:09 by armosnie          #+#    #+#             */
/*   Updated: 2026/03/18 16:29:36 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _size(n) {

   _tab.reserve(n);
}

Span::~Span() {}

Span::Span(const Span &copy) : _size(copy._size), _tab(copy._tab) {}

Span &Span::operator=(const Span &copy) {
   
   if (this != &copy) {
      _size = copy._size;
      _tab = copy._tab;
   }
   return *this;
}

void  Span::addNumber(int num) {
   
   if (_tab.size() >= _size)
      throw TabIsFull();
   _tab.push_back(num);
}

int Span::shortestSpan() const {

   if (_tab.size() <= 1)
      throw NotEnoughInt();

   std::vector<int> sortTab = _tab;
   std::sort(sortTab.begin(), sortTab.end());
   
   long min = std::numeric_limits<long>::max();
   for (size_t i = 1; i < sortTab.size(); i++) {
      long diff = static_cast<long>(sortTab[i]) - static_cast<long>(sortTab[i - 1]);
      if (diff < min)
         min = diff;
   }
   return static_cast<int>(min);
}

int Span::longestSpan() const {
   
   if (_tab.size() <= 1)
      throw NotEnoughInt();
   
   std::vector<int> sortTab = _tab;
   sort(sortTab.begin(), sortTab.end());
   return sortTab.back() - sortTab.front();
}