/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:47:11 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/25 15:01:00 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPtr = &string;
    std::string &stringRef = string;
    
    std::cout << "Adresse de string: " << &string << std::endl;
    std::cout << "Adresse dans stringPTR: " << stringPtr << std::endl;
    std::cout << "Adresse dans stringREF: " << &stringRef << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Valeur de string: " << string << std::endl;
    std::cout << "Valeur pointée par stringPTR: " << *stringPtr << std::endl;
    std::cout << "Valeur pointée par stringREF: " << stringRef << std::endl;
    return 0;
}