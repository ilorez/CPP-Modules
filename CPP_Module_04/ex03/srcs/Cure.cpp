/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:39:18 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/23 14:39:32 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/Debug.hpp"

// constructors
Cure::Cure():AMateria("cure"){};
Cure::Cure(std::string const &type):AMateria(type){};
Cure::Cure(Cure const &copy):AMateria(copy){};

// assignment operator overloading 
// forbidden

// destructor
Cure::~Cure(){};


// member functions
Cure* Cure::clone() const
{
  DEBUG_INFO("Cure cloned");
  return (new Cure(*this));
}


void Cure::use(ICharacter& target)
{
  DEBUG_INFO("Cure::use on " << target.getName());
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
