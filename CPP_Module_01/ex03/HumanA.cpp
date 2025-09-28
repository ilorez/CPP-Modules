/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:01:31 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/28 14:21:04 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"

void HumanA::attack() const {
  std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
