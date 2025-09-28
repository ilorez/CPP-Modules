/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:51:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/28 16:22:37 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
#define HARL_CPP

#include <iostream>

class Harl {
  private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
  public:
    Harl();
    ~Harl();
    void complain(std::string level );
};

#endif
