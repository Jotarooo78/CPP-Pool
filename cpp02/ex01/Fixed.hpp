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
};

std::ostream& operator<<(std::ostream& cout, const Fixed& fixedToDisplay);

#endif