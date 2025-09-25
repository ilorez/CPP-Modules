/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:59:50 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/25 20:21:56 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
  _i = 0;
  _len = 0;
}

std::string PhoneBook::_getUserField(std::string label)
{
  std::string input;
  std::cout << label << ": ";
  if (!std::getline(std::cin, input))
  {
    std::cout << std::endl << "reach EOF, exit program" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (!input[0])
  {
    std::cout << std::endl << "you can't leave " << label << " empty!" << std::endl;
    return PhoneBook::_getUserField(label);
  }
  return input;
}

void PhoneBook::add_new_contact()
{
  Contact c;
  // get contact info rom user
  c.setFirstName(PhoneBook::_getUserField("First Name"));
  c.setLastName(PhoneBook::_getUserField("Last Name"));
  c.setNickName(PhoneBook::_getUserField("Nickname"));
  c.setPhoneNum(PhoneBook::_getUserField("Phone Number"));
  c.setSecret(PhoneBook::_getUserField("Darkest Secret"));
  // add contact to phone book
  _list[_i] = c;
  if (++_i >= PB_SIZE)
    _i = 0;
  if (_len < PB_SIZE)
    _len += 1;
  
}

void PhoneBook::_fieldPrint(std::string label, std::string value)
{
  std::cout << label;
  std::cout << value;
  std::cout << std::endl;
}

bool PhoneBook::display_contact(int i)
{
  if (i == 0)
    return (true);
  if (i < 0 || i > _len)
  {
    std::cout << i << " is out of indexs range :<!" << std::endl;
    return (true);
  }
  i--;
  PhoneBook::_fieldPrint("First Name: ", _list[i].getFirstName());
  PhoneBook::_fieldPrint("Last Name: ", _list[i].getLastName());
  PhoneBook::_fieldPrint("Nickame: ", _list[i].getNickName());
  PhoneBook::_fieldPrint("Phone Number: ", _list[i].getPhoneNum());
  PhoneBook::_fieldPrint("Darkest Secret: ", _list[i].getSecret());
  return (false);
}


std::string PhoneBook::_truncate(std::string str)
{
  if (str.length() > UNIT_W)
    return (str.substr(0, UNIT_W -1) + ".");
  return str;
}

void PhoneBook::_formatColumn(int index, std::string firstn, std::string lastn, std::string nickn)
{
    std::cout << "|" << std::setw(UNIT_W) << index 
          << "|" << std::setw(UNIT_W) << PhoneBook::_truncate(firstn)
          << "|" << std::setw(UNIT_W) <<  PhoneBook::_truncate(lastn)
          << "|" << std::setw(UNIT_W) << PhoneBook::_truncate(nickn)
          << "|" << std::endl;
}

void PhoneBook::show_contacts_table()
{
  std::cout << "|" << std::setw(UNIT_W) << "index"
          << "|" << std::setw(UNIT_W) << "firstName"
          << "|" << std::setw(UNIT_W) << "lastName"
          << "|" << std::setw(UNIT_W) << "nickname"
          << "|" << std::endl;
  for (int i =0; i < _len; i++)
  {
    _formatColumn(i+1, _list[i].getFirstName(), _list[i].getLastName(), _list[i].getNickName());
  }
}

bool PhoneBook::isempty()
{
  return (!_len);
}

