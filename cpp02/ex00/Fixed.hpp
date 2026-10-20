#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    private :

        int _value;
        static const int _f_bits = 8;

    public :

        Fixed();
        ~Fixed();
        Fixed(const Fixed &fixedCopy);
        Fixed &operator=(const Fixed &fixedCopy);
        int getRawBits() const;
        void setRawBits(int const value);
};

#endif