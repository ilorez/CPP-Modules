/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 09:21:16 by znajdaou          #+#    #+#             */
/*   Updated: 2026/05/09 10:36:06 by znajdaou         ###   ########.fr       */
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
    Array(unsigned int n): _n(n), _arr(new T[n]()){
    }
    Array(const Array &copy){
      *this = copy;
    };

    Array& operator=(const Array &copy)
    {
      if (this != &copy)
      {
        _n = copy._n;
        this->_arr = new T[_n];
        for (unsigned int i = 0; i < _n; i++)
          this->_arr[i] = copy._arr[i];
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
