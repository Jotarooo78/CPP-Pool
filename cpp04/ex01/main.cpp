/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:22:13 by armosnie          #+#    #+#             */
/*   Updated: 2026/02/06 17:22:15 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void testDeepCopy() {
    std::cout << "\n=== TEST DEEP COPY ===" << std::endl;
    
    Dog original;
    original.getBrain()->setIdea(0, "Je suis l'original");
    original.getBrain()->setIdea(1, "Idee originale 2");
    
    // Test copy constructor
    Dog copy1(original);
    copy1.getBrain()->setIdea(0, "Je suis la copie 1");
    
    std::cout << "Original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy1 idea[0]: " << copy1.getBrain()->getIdea(0) << std::endl;
    
    // Les deux doivent être DIFFERENTES (deep copy)
    if (original.getBrain()->getIdea(0) != copy1.getBrain()->getIdea(0)) {
        std::cout << "✅ Deep copy OK (copy constructor)" << std::endl;
    } else {
        std::cout << "❌ SHALLOW COPY DETECTED!" << std::endl;
    }
    
    // Test assignment operator
    Dog copy2;
    copy2 = original;
    copy2.getBrain()->setIdea(1, "Je suis la copie 2");
    
    std::cout << "Original idea[1]: " << original.getBrain()->getIdea(1) << std::endl;
    std::cout << "Copy2 idea[1]: " << copy2.getBrain()->getIdea(1) << std::endl;
    
    if (original.getBrain()->getIdea(1) != copy2.getBrain()->getIdea(1)) {
        std::cout << "✅ Deep copy OK (assignment operator)" << std::endl;
    } else {
        std::cout << "❌ SHALLOW COPY DETECTED!" << std::endl;
    }
}

void testAnimalArray() {
    std::cout << "\n=== TEST ANIMAL ARRAY ===" << std::endl;
    
    const int size = 6;
    Animal* animals[size];
    
    // Moitié Dogs, moitié Cats
    for (int i = 0; i < size; i++) {
        if (i < size / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }
    
    std::cout << "\n--- Using animals ---" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n--- Deleting animals ---" << std::endl;
    for (int i = 0; i < size; i++) {
        delete animals[i];
    }
}

int main() {
    
    std::cout << "=== EX01 TESTS ===" << std::endl;
    
    // Test du sujet
    std::cout << "\n--- Subject test ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; // should not create a leak
    delete i;
    
    // Tests supplémentaires
    testDeepCopy();
    testAnimalArray();
    
    std::cout << "\n=== END ===" << std::endl;
    
    return 0;
}