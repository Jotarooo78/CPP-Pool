/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaunito <armaunito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:50:03 by armaunito         #+#    #+#             */
/*   Updated: 2026/02/05 16:10:37 by armaunito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== TEST 1: Creation de formulaires valides ===" << std::endl;
    try {
        Form form1("Tax Form", 50, 25);
        std::cout << form1 << std::endl;
        
        Form form2("Building Permit", 100, 75);
        std::cout << form2 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 2: Creation de formulaires invalides ===" << std::endl;
    try {
        Form formTooHigh("Invalid High", 0, 50);
    }
    catch (std::exception &e) {
        std::cout << "Exception attrapée: " << e.what() << std::endl;
    }
    
    try {
        Form formTooLow("Invalid Low", 50, 151);
    }
    catch (std::exception &e) {
        std::cout << "Exception attrapée: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 3: Signature réussie ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 30);
        Form contract("Contract", 50, 25);
        
        std::cout << alice << std::endl;
        std::cout << contract << std::endl;
        
        alice.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 4: Signature échouée (grade trop bas) ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        Form importantDoc("Important Document", 50, 25);
        
        std::cout << bob << std::endl;
        std::cout << importantDoc << std::endl;
        
        bob.signForm(importantDoc);
        std::cout << importantDoc << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 5: Plusieurs signatures ===" << std::endl;
    try {
        Bureaucrat john("John", 1);
        Bureaucrat jane("Jane", 150);
        Form vipForm("VIP Form", 5, 3);
        
        std::cout << vipForm << std::endl;
        
        jane.signForm(vipForm);
        john.signForm(vipForm);
        
        std::cout << vipForm << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 6: Cas limites ===" << std::endl;
    try {
        Bureaucrat perfect("Perfect", 1);
        Form easyForm("Easy Form", 150, 150);
        Form hardForm("Hard Form", 1, 1);
        
        std::cout << "\n--- Easy Form ---" << std::endl;
        perfect.signForm(easyForm);
        std::cout << easyForm << std::endl;
        
        std::cout << "\n--- Hard Form ---" << std::endl;
        perfect.signForm(hardForm);
        std::cout << hardForm << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 7: Test de copie ===" << std::endl;
    try {
        Form original("Original", 75, 50);
        Bureaucrat signer("Signer", 50);
        
        signer.signForm(original);
        std::cout << "Original: " << original << std::endl;
        
        Form copy(original);
        std::cout << "Copy: " << copy << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}