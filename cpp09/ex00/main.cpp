/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:29:47 by armaunito         #+#    #+#             */
/*   Updated: 2026/04/09 12:57:13 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
   
   if (argc != 2) {
      std::cerr << "Usage: ./btc <input_file>" << std::endl;
      return 1;
   }
   if (argc == 2) {
      int len = strlen(argv[1]);
      if (len >= 4 && strncmp(argv[1] + len - 4, ".txt", 4) == 0) {
         BitcoinExchange btc;
         btc.parseAndDisplay(argv[1]);
         return 0;
      }
   }
   return 1;
}