/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:56:56 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/24 18:57:23 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

// setters
void Contact::setFirstName(std::string v)
{
  _firstn = v;
}

void Contact::setLastName(std::string v)
{
  _lastn = v;
}

void Contact::setNickName(std::string v)
{
  _nickname = v;
}
void Contact::setPhoneNum(std::string v)
{
  _num = v;
}
void Contact::setSecret(std::string v)
{
  _secret = v;
}

// getters
std::string Contact::getFirstName() const{
  return _firstn;
}

std::string Contact::getLastName() const{
  return _lastn;
}

std::string Contact::getNickName() const{
  return _nickname;
}

std::string Contact::getPhoneNum() const{
  return _num;
}

std::string Contact::getSecret() const{
  return _secret;
}
// ========================


