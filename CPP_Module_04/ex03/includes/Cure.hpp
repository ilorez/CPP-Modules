/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 21:08:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/22 21:19:45 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria {
  public:
    // Orthodox Canonical Form
    Cure();
    ~Cure();
    Cure(const Cure &copy);
    //Cure& operator=(const Cure &copy);

    // Custom Constructors
    Cure(std::string const &type);
    
    // member functions
    Cure* clone() const;
    void use(ICharacter& target);
};

#endif
