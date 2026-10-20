/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:12:41 by armosnie          #+#    #+#             */
/*   Updated: 2025/12/02 13:50:37 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc == 2) {
        Harl tab;
        int lvl = -1;
        std::string input = argv[1];
        if (input == "DEBUG")
            lvl = 0;
        else if (input == "INFO")
            lvl = 1;
        else if (input == "WARNING")
            lvl = 2;
        else if (input == "ERROR")
            lvl = 3;
        switch (lvl) {
            case 0:
                tab.complain("DEBUG");
            case 1:
                tab.complain("INFO");
            case 2:
                tab.complain("WARNING");
            case 3:
                tab.complain("ERROR");
            break;
            default :
                std::cout << "Probably complaining about insignificant problems" << std::endl;
        }
    }
    return 0;
}