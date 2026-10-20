#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

   private:
      int _value;
      static const int _f_bits = 8;

   public:
      Fixed();
      Fixed(const Fixed& fixedCopy);
      Fixed(const int num);
      Fixed(const float fl);
      ~Fixed();
      
      Fixed& operator=(const Fixed& fixedCopy);

      int getRawBits(void) const;
      void setRawBits(int const raw);
      float toFloat(void) const;
      int toInt(void) const;

      //opérateurs de comparaison

      bool operator>(const Fixed& obj2) const;
      bool operator<(const Fixed& obj2) const;
      bool operator<=(const Fixed& obj2) const;
      bool operator>=(const Fixed& obj2) const;
      bool operator==(const Fixed& obj2) const;
      bool operator!=(const Fixed& obj2) const;
      
      //opérateurs arithmétiques

      Fixed operator+(const Fixed& obj2) const;
      Fixed operator-(const Fixed& obj2) const;
      Fixed operator*(const Fixed& obj2) const;
      Fixed operator/(const Fixed& obj2) const;

      //opérateurs d'incrémentation/décrémentation

      Fixed& operator++();
      Fixed operator++(int);
      Fixed& operator--();
      Fixed operator--(int);

      //fonctions statiques min et max

      static Fixed& min(Fixed& obj1, Fixed& obj2);
      static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
      static Fixed& max(Fixed& obj1, Fixed& obj2);
      static const Fixed& max(const Fixed& obj1, const Fixed& obj2); 
};

std::ostream& operator<<(std::ostream& cout, const Fixed& fixedToDisplay);

#endif