/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaunito <armaunito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:43:14 by armaunito         #+#    #+#             */
/*   Updated: 2026/02/08 15:55:20 by armaunito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:43:14 by armaunito         #+#    #+#             */
/*   Updated: 2026/02/08 XX:XX:XX by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void printHeader(const std::string& title) {
    std::cout << "\n╔══════════════════════════════════════╗" << std::endl;
    std::cout << "║  " << title;
    for (size_t i = title.length(); i < 34; i++)
        std::cout << " ";
    std::cout << "║" << std::endl;
    std::cout << "╚══════════════════════════════════════╝\n" << std::endl;
}

void testSubject() {
    printHeader("TEST DU SUJET");
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
}

void testFullInventory() {
    printHeader("TEST INVENTAIRE PLEIN (4 slots)");
    
    Character* hero = new Character("Hero");
    
    // Remplir les 4 slots
    hero->equip(new Ice());
    hero->equip(new Cure());
    hero->equip(new Ice());
    hero->equip(new Cure());
    
    std::cout << "→ Tentative d'equip un 5ème item (doit être ignoré):" << std::endl;
    AMateria* overflow = new Ice();
    hero->equip(overflow);
    
    // overflow n'a pas été equipé, donc on doit le delete nous-mêmes
    delete overflow;
    
    delete hero;
}

void testUnequipAndMemory() {
    printHeader("TEST UNEQUIP & GESTION MEMOIRE");
    
    Character* mage = new Character("Gandalf");
    
    AMateria* ice1 = new Ice();
    AMateria* cure1 = new Cure();
    
    mage->equip(ice1);
    mage->equip(cure1);
    
    std::cout << "→ Utilisation avant unequip:" << std::endl;
    Character dummy("Target");
    mage->use(0, dummy);
    mage->use(1, dummy);
    
    std::cout << "\n→ Unequip slot 0 (Ice):" << std::endl;
    mage->unequip(0);
    
    std::cout << "→ Tentative d'utiliser slot 0 après unequip (ne doit rien faire):" << std::endl;
    mage->use(0, dummy);
    
    std::cout << "→ Slot 1 (Cure) fonctionne encore:" << std::endl;
    mage->use(1, dummy);
    
    // IMPORTANT: après unequip, on doit delete manuellement
    delete ice1;
    
    delete mage;
}

void testDeepCopy() {
    printHeader("TEST DEEP COPY (Character)");
    
    Character* original = new Character("Original");
    original->equip(new Ice());
    original->equip(new Cure());
    
    std::cout << "→ Copie du personnage:" << std::endl;
    Character* copy = new Character(*original);
    
    std::cout << "\n→ Original utilise ses materias:" << std::endl;
    Character target("Target");
    original->use(0, target);
    original->use(1, target);
    
    std::cout << "\n→ Copie utilise ses materias (deep copy = nouvelles instances):" << std::endl;
    copy->use(0, target);
    copy->use(1, target);
    
    std::cout << "\n→ Suppression de l'original:" << std::endl;
    delete original;
    
    std::cout << "\n→ La copie fonctionne toujours (preuve de deep copy):" << std::endl;
    copy->use(0, target);
    
    delete copy;
}

void testMateriaSourceLimits() {
    printHeader("TEST MATERIASOURCE (4 templates max)");
    
    MateriaSource* src = new MateriaSource();
    
    std::cout << "→ Apprentissage de 4 materias:" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    std::cout << "\n→ Tentative d'apprendre une 5ème (doit être ignorée):" << std::endl;
    src->learnMateria(new Ice());  // Sera delete automatiquement dans votre implementation
    
    std::cout << "\n→ Création de materias à partir des templates:" << std::endl;
    AMateria* test1 = src->createMateria("ice");
    AMateria* test2 = src->createMateria("cure");
    AMateria* test3 = src->createMateria("unknown");  // Doit retourner NULL
    
    std::cout << "Ice created: " << (test1 ? "✅" : "❌") << std::endl;
    std::cout << "Cure created: " << (test2 ? "✅" : "❌") << std::endl;
    std::cout << "Unknown (NULL): " << (test3 ? "❌" : "✅") << std::endl;
    
    delete test1;
    delete test2;
    // test3 est NULL, pas besoin de delete
    
    delete src;
}

void testInvalidOperations() {
    printHeader("TEST OPERATIONS INVALIDES");
    
    Character* hero = new Character("Hero");
    Character target("Dummy");
    
    std::cout << "→ Use sur slot vide:" << std::endl;
    hero->use(0, target);  // Slot vide, ne doit rien faire
    
    std::cout << "\n→ Use sur index invalide:" << std::endl;
    hero->use(-1, target);  // Index négatif
    hero->use(99, target);  // Index trop grand
    
    std::cout << "\n→ Unequip sur slot vide:" << std::endl;
    hero->unequip(2);  // Slot vide
    
    std::cout << "\n→ Unequip sur index invalide:" << std::endl;
    hero->unequip(-5);
    hero->unequip(42);
    
    std::cout << "\n→ Equip NULL:" << std::endl;
    hero->equip(NULL);  // Ne doit rien faire
    
    delete hero;
}

void testAssignmentOperator() {
    printHeader("TEST ASSIGNMENT OPERATOR");
    
    Character* hero1 = new Character("Hero1");
    hero1->equip(new Ice());
    hero1->equip(new Cure());
    
    Character* hero2 = new Character("Hero2");
    hero2->equip(new Ice());
    
    std::cout << "→ Avant assignation:" << std::endl;
    Character target("Target");
    std::cout << "Hero1: ";
    hero1->use(0, target);
    std::cout << "Hero2: ";
    hero2->use(0, target);
    
    std::cout << "\n→ Assignation: hero2 = hero1" << std::endl;
    *hero2 = *hero1;
    
    std::cout << "\n→ Après assignation:" << std::endl;
    std::cout << "Hero2 a maintenant l'inventaire de Hero1:" << std::endl;
    hero2->use(0, target);
    hero2->use(1, target);
    
    delete hero1;
    delete hero2;
}

int main() {
    testSubject();
    testFullInventory();
    testUnequipAndMemory();
    testDeepCopy();
    testMateriaSourceLimits();
    testInvalidOperations();
    testAssignmentOperator();
    
    printHeader("TOUS LES TESTS TERMINES");
    std::cout << "Vérifiez avec valgrind pour les fuites mémoire:\n";
    std::cout << "valgrind --leak-check=full ./Polymorphism_4\n" << std::endl;
    
    return 0;
}