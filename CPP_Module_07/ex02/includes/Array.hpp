/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 09:21:16 by znajdaou          #+#    #+#             */
/*   Updated: 2026/05/13 14:54:33 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array {
  private:
    unsigned int _n;
    T* _arr;
  public:
    // orthox
    Array(): _n(0), _arr(new T[0]){}
    Array(unsigned int n): _n(n), _arr(new T[n]()){}
    Array(const Array &copy){
      _n = copy._n;
      _arr = new T[_n];
      for (unsigned int i = 0; i < _n; i++)
        _arr[i] = copy._arr[i];
    };

    Array& operator=(const Array &copy)
    {
      if (this != &copy)
      {
        _n = copy._n;
        T* old = this->_arr;
        this->_arr = new T[_n];
        for (unsigned int i = 0; i < _n; i++)
          this->_arr[i] = copy._arr[i];
        delete[] old;
      }
      return (*this);
    }

    ~Array(){
      std::cout << "Destructor called" << std::endl;
      delete[] _arr;
    }

    // exeptions
    class OutOfBoundExp: public std::exception {
      const char* what() const throw() {
        return "index out of bound";
      }
    };

    // operators
    T& operator[](unsigned int index)
    {
      if (index >= _n)
        throw OutOfBoundExp(); 
      return (_arr[index]);
    }

    const T& operator[](unsigned int index) const
    {
      if (index >= _n)
        throw OutOfBoundExp(); 
      return (_arr[index]);
    }

    // getters
    unsigned int size() const
    {
      return _n;
    }
};

#endif
