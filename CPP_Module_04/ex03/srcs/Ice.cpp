/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:39:13 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/23 14:39:14 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/Debug.hpp"

// constructors
Ice::Ice():AMateria("ice"){};
Ice::Ice(std::string const &type):AMateria(type){};
Ice::Ice(Ice const &copy):AMateria(copy){};

// assignment operator overloading 
// forbidden

// destructor
Ice::~Ice(){};


// member functions
Ice* Ice::clone() const
{
  DEBUG_INFO("Ice cloned");
  return (new Ice(*this));
}


void Ice::use(ICharacter& target)
{
  DEBUG_INFO("Ice::use on " << target.getName());
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
