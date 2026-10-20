/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:34:43 by armosnie          #+#    #+#             */
/*   Updated: 2026/03/04 17:37:30 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template <typename T>
void printElement(T const & element) {
    std::cout << element << " ";
}

void increment(int & element) {
    element += 1;
}

void toUpperCase(std::string & str) {
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Tableau original : ";
    iter(intArray, intLength, printElement<int>);
    std::cout << std::endl;
    
    iter(intArray, intLength, increment);
    
    std::cout << "Après incrémentation : ";
    iter(intArray, intLength, printElement<int>);
    std::cout << std::endl;
    
    std::string strArray[] = {"bonjour", "monde", "c++"};
    size_t strLength = sizeof(strArray) / sizeof(strArray[0]);
    
    std::cout << "\nStrings originales : ";
    iter(strArray, strLength, printElement<std::string>);
    std::cout << std::endl;
    
    iter(strArray, strLength, toUpperCase);
    
    std::cout << "Après majuscule : ";
    iter(strArray, strLength, printElement<std::string>);
    std::cout << std::endl;
    
    return 0;
}