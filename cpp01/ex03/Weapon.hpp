#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
    private :
        std::string _weaponType;

    public :
        Weapon(std::string weaponType);
        ~Weapon();
        std::string getWeaponType() const;
        void setWeaponType(std::string weaponType);
};

void attack();

#endif