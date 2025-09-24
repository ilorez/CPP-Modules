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
  firstn = v;
}

void Contact::setLastName(std::string v)
{
  lastn = v;
}

void Contact::setNickName(std::string v)
{
  nickname = v;
}
void Contact::setPhoneNum(std::string v)
{
  num = v;
}
void Contact::setSecret(std::string v)
{
  secret = v;
}

// getters
std::string Contact::getFirstName() const{
  return firstn;
}

std::string Contact::getLastName() const{
  return lastn;
}

std::string Contact::getNickName() const{
  return nickname;
}

std::string Contact::getPhoneNum() const{
  return num;
}

std::string Contact::getSecret() const{
  return secret;
}
// ========================


