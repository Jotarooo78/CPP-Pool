/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaunito <armaunito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:50:03 by armaunito         #+#    #+#             */
/*   Updated: 2026/02/05 18:46:18 by armaunito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void printSeparator(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main()
{
    // ========== TEST 1: ShrubberyCreationForm ==========
    printSeparator("TEST 1: ShrubberyCreationForm");
    try
    {
        Bureaucrat bob("Bob", 140);
        ShrubberyCreationForm shrub("home");
        
        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;
        
        // Tenter d'exécuter sans signer (doit échouer)
        std::cout << "\n--- Tentative d'exécution sans signature ---" << std::endl;
        bob.executeForm(shrub);
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try
    {
        Bureaucrat bob("Bob", 140);
        Bureaucrat charlie("Charlie", 130);  // Grade suffisant pour exécuter
        ShrubberyCreationForm shrub("garden");
        
        // Bob signe (grade 140 < 145 ✓)
        std::cout << "\n--- Signature par Bob ---" << std::endl;
        bob.signForm(shrub);
        
        // Bob tente d'exécuter (grade 140 > 137 ✗)
        std::cout << "\n--- Bob tente d'exécuter (doit échouer) ---" << std::endl;
        bob.executeForm(shrub);
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try
    {
        Bureaucrat charlie("Charlie", 130);
        ShrubberyCreationForm shrub2("park");
        
        // Charlie peut signer ET exécuter
        std::cout << "\n--- Charlie signe et exécute ---" << std::endl;
        charlie.signForm(shrub2);
        charlie.executeForm(shrub2);
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // ========== TEST 2: RobotomyRequestForm ==========
    printSeparator("TEST 2: RobotomyRequestForm");
    try
    {
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robot("Bender");
        
        std::cout << alice << std::endl;
        std::cout << robot << std::endl;
        
        alice.signForm(robot);
        
        // Tenter plusieurs fois (50% de succès)
        std::cout << "\n--- Tentatives de robotomisation ---" << std::endl;
        for (int i = 0; i < 5; i++)
        {
            std::cout << "\nTentative " << (i + 1) << ":" << std::endl;
            alice.executeForm(robot);
        }
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // ========== TEST 3: PresidentialPardonForm ==========
    printSeparator("TEST 3: PresidentialPardonForm");
    try
    {
        Bureaucrat lowGrade("LowGrade", 50);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << lowGrade << std::endl;
        std::cout << pardon << std::endl;
        
        // Grade trop bas pour signer (doit échouer)
        std::cout << "\n--- Tentative de signature avec grade insuffisant ---" << std::endl;
        lowGrade.signForm(pardon);
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Ford Prefect");
        
        std::cout << "\n--- Signature et exécution par le président ---" << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // ========== TEST 4: Grade insuffisant pour exécuter ==========
    printSeparator("TEST 4: Grade insuffisant pour exécuter");
    try
    {
        Bureaucrat signer("Signer", 20);
        Bureaucrat executor("Executor", 50);
        PresidentialPardonForm pardon("Zaphod");
        
        std::cout << signer << std::endl;
        std::cout << executor << std::endl;
        std::cout << pardon << std::endl;
        
        // Le signer peut signer (grade 20 ≤ 25 ✓)
        std::cout << "\n--- Signature par quelqu'un qui a le grade ---" << std::endl;
        signer.signForm(pardon);
        
        // Mais l'executor ne peut pas exécuter (grade 50 > 5 requis ✗)
        std::cout << "\n--- Tentative d'exécution avec grade insuffisant ---" << std::endl;
        executor.executeForm(pardon);
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // ========== TEST 5: Tous les formulaires avec un bureaucrate puissant ==========
    printSeparator("TEST 5: Super Bureaucrate teste tout");
    try
    {
        Bureaucrat boss("Boss", 1);
        
        ShrubberyCreationForm shrub("office");
        RobotomyRequestForm robot("Marvin");
        PresidentialPardonForm pardon("Trillian");
        
        std::cout << boss << std::endl;
        
        // Shrubbery
        std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
        boss.signForm(shrub);
        boss.executeForm(shrub);
        
        // Robotomy
        std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
        boss.signForm(robot);
        boss.executeForm(robot);
        
        // Presidential
        std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
        boss.signForm(pardon);
        boss.executeForm(pardon);
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    printSeparator("FIN DES TESTS");
    
    return 0;
}