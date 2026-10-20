/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:22:36 by armaunito         #+#    #+#             */
/*   Updated: 2026/03/18 16:06:06 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main() {
    try {
        std::vector<int> vec;
        Span sp(10000);
        std::srand(std::time(NULL));
        
        for (int i = 0; i < 10000; ++i) {
            vec.push_back(rand());
        }
        sp.addNumbers(vec.begin(), vec.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}