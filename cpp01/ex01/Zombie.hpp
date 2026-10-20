#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
    private :
        std::string _name;

    public :
        Zombie();
        ~Zombie();
        void setName(std::string &name);
        void    announce(int n);

};

Zombie *zombieHorde(int n, std::string name);

#endif