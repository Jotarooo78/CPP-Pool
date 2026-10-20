/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:19:16 by marvin            #+#    #+#             */
/*   Updated: 2025/12/08 16:19:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {

    // std::cout << "Default Constructor called" << std::endl;
}

Fixed::~Fixed() {

    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int num) {

    int tmp_num;
    // std::cout << "Int Constructor called" << std::endl;
    tmp_num = num << this->_f_bits;
    this->_value = tmp_num;
}

Fixed::Fixed(const float fl) {

    float tmp_fl;
    // std::cout << "Float Constructor called" << std::endl;
    tmp_fl = fl * (1 << this->_f_bits);
    this->_value = roundf(tmp_fl);
}

Fixed::Fixed(const Fixed &fixedCopy) {

    // std::cout << "Constructor copy called" << std::endl;
    this->_value = fixedCopy._value;

}

Fixed& Fixed::operator=(const Fixed &fixedCopy) {

    // std::cout << "Copy assignment called" << std::endl;
    if (this != &fixedCopy)
        this->_value = fixedCopy._value;
    return *this;
}

int Fixed::getRawBits(void) const {

    return _value;
}

void Fixed::setRawBits(int const value) {

    _value = value;
}

float Fixed::toFloat(void) const {

    return (float)_value / (1 << _f_bits);
}

int Fixed::toInt(void) const {

    return _value >> _f_bits;
}


std::ostream& operator<<(std::ostream& cout, const Fixed& fixedToDisplay) {

    cout << fixedToDisplay.toFloat();
    return cout;
}

bool Fixed::operator>(const Fixed& obj2) const {

    if (this->_value > obj2._value)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed& obj2) const {

    if (this->_value < obj2._value)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed& obj2) const {

    if (this->_value <= obj2._value)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed& obj2) const {

    if (this->_value >= obj2._value)
        return true;
    return false;
}

bool Fixed::operator==(const Fixed& obj2) const {

    if (this->_value == obj2._value)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed& obj2) const {

    if (this->_value != obj2._value)
        return true;
    return false;
}

Fixed Fixed::operator+(const Fixed& obj2) const {

    Fixed result;
    result.setRawBits(this->_value + obj2._value);
    return result;
}

Fixed Fixed::operator-(const Fixed& obj2) const {

    Fixed result;
    result.setRawBits(this->_value - obj2._value);
    return result;
}

Fixed Fixed::operator*(const Fixed& obj2) const {

    Fixed result;
    result.setRawBits((this->_value * obj2._value) >> _f_bits);
    return result;
}

Fixed Fixed::operator/(const Fixed& obj2) const {

    Fixed result;
    result.setRawBits((this->_value << _f_bits) / obj2._value);
    return result;
}

Fixed& Fixed::operator++() {

    _value++;
    return *this;
}

Fixed Fixed::operator++(int) {

    Fixed result = *this;
    _value++;
    return result;
}

Fixed& Fixed::operator--() {

    _value--;
    return *this;
}

Fixed Fixed::operator--(int) {

    Fixed result = *this;
    _value--;
    return result;
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2) {

    if (obj1._value < obj2._value)
        return obj1;
    else
        return obj2;
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2) {

    if (obj1._value < obj2._value)
        return obj1;
    else
        return obj2;
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2) {

    if (obj1._value > obj2._value)
        return obj1;
    else
        return obj2;
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2) {

    if (obj1._value > obj2._value)
        return obj1;
    else
        return obj2;
}

