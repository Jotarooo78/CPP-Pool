#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstddef>

template <typename T>
class Array {

    private :

        T *_elements;
        unsigned int _size;

    public :

        Array() : _elements(NULL), _size(0) {}
        Array(unsigned int n) : _elements(new T[n]()), _size(n) {}
        Array(Array const &copy) : _elements(NULL), _size(0) {
            *this = copy;
        }
        ~Array() {
            delete []_elements;
        }

        Array &operator=(Array const &copy) {

            if (this != &copy) {
                delete []_elements;
                _size = copy._size;
                _elements = new T[_size]();
                for (unsigned int i = 0; i < _size; i++) {
                    _elements[i] = copy._elements[i];
                }
            }
            return *this;
        }

        T &operator[](unsigned int index) {
            
            if (index >= _size)
                throw std::exception();
            return _elements[index];
        }
        T const &operator[](unsigned int index) const {
            
            if (index >= _size)
                throw std::exception();
            return _elements[index];
        }
        
        unsigned int size() const {
            return _size;
        }
};

#endif