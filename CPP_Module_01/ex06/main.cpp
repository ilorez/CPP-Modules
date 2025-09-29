/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:26:00 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/29 15:18:24 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Harl.hpp"
#include <cstdlib>

int main(int ac, char **av)
{
    Harl that_one_guy;
    std::string level;

    if (ac != 2)
    {
      std::cerr << "Error: Require one argumnet" << std::endl;
      return (EXIT_FAILURE);
    }
    level = av[1];
    that_one_guy.complain(level);
}
