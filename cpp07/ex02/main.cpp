/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:34:43 by armosnie          #+#    #+#             */
/*   Updated: 2026/03/04 18:28:50 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "Array.hpp"
#include <iostream>
#include <string>

// Fonction template pour afficher un Array
template <typename T>
void displayArray(Array<T> const & arr, std::string const & name) {
    std::cout << name << " (size " << arr.size() << "): ";
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== Test 1: Constructeur par défaut ===" << std::endl;
    Array<int> empty;
    std::cout << "Tableau vide, size = " << empty.size() << std::endl;
    // empty[0];  // Cela lancerait une exception
    
    std::cout << "\n=== Test 2: Constructeur avec taille ===" << std::endl;
    Array<int> numbers(5);
    displayArray(numbers, "numbers (après construction)");
    
    // Remplir le tableau
    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 10;
    }
    displayArray(numbers, "numbers (après remplissage)");
    
    std::cout << "\n=== Test 3: Constructeur par copie ===" << std::endl;
    Array<int> copy(numbers);  // Copie
    displayArray(copy, "copy");
    
    // Modifier l'original pour vérifier la deep copy
    numbers[0] = 999;
    std::cout << "Après modification de numbers[0] = 999:" << std::endl;
    displayArray(numbers, "numbers");
    displayArray(copy, "copy (doit être inchangé)");
    
    std::cout << "\n=== Test 4: Opérateur d'affectation ===" << std::endl;
    Array<int> assigned;
    assigned = numbers;
    displayArray(assigned, "assigned");
    
    numbers[1] = 888;
    std::cout << "Après modification de numbers[1] = 888:" << std::endl;
    displayArray(numbers, "numbers");
    displayArray(assigned, "assigned (doit être inchangé)");
    
    std::cout << "\n=== Test 5: Tableau de strings ===" << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "C++";
    displayArray(strings, "strings");
    
    std::cout << "\n=== Test 6: Tableau const ===" << std::endl;
    Array<std::string> const constStrings(strings);
    std::cout << "constStrings[0] = " << constStrings[0] << std::endl;
    // constStrings[0] = "Test";  // Erreur de compilation (bon !)
    
    std::cout << "\n=== Test 7: Gestion des exceptions ===" << std::endl;
    try {
        std::cout << "Tentative d'accès à numbers[10] (size = " << numbers.size() << ")..." << std::endl;
        std::cout << numbers[10] << std::endl;  // Devrait lancer une exception
    }
    catch (std::exception & e) {
        std::cout << "Exception attrapée : index out of bounds" << std::endl;
    }
    
    std::cout << "\n=== Test 8: Tableau vide ===" << std::endl;
    Array<double> empty2;
    std::cout << "empty2.size() = " << empty2.size() << std::endl;
    try {
        empty2[0];
    }
    catch (std::exception & e) {
        std::cout << "Exception attrapée pour empty2[0]" << std::endl;
    }
    
    return 0;
}