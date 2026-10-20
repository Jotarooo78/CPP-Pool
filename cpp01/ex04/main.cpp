/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:46:58 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/28 11:55:48 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string content, std::string s1, std::string s2){
    
    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = content.find(s1, pos)) != std::string::npos){
        result += content.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += content.substr(pos);
    
    return result;
}   


int main(int argc, char **argv)
{
    if (argc != 4)
        return 1;
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream infile(filename.c_str());
    if (!infile.is_open()){
        std::cout << "creating infile failed" << std::endl;
        return 1;
    }
    std::string line;
    std::string content;
    while (std::getline(infile, line))
    {
        content+= line;
        if (!infile.eof())
            content+= "\n"; 
    }
    infile.close();
    content = replaceAll(content, s1, s2);
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open()){
        std::cout << "creating outfile failed" << std::endl;
        return 1;
    }
    outfile << content;
    outfile.close();
    std::cout << "creating replace file success" << std::endl;
    return 0;
}