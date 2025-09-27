/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:21:48 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/27 22:43:03 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
  std::string _name;
public:
  Zombie(std::string name):_name(name){};
  Zombie();
  ~Zombie();
  void announce(void) const;
  void setZombieName(std::string value);
  std::string getZombieName(void) const;
};

void randomChump( std::string name);
Zombie* newZombie( std::string name);

#endif
