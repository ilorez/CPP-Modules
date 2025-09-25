/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:59:50 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/25 19:36:33 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
  _i = 0;
  _len = 0;
}

std::string PhoneBook::_get_user_field(std::string label)
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
    return PhoneBook::_get_user_field(label);
  }
  return input;
}

void PhoneBook::add_new_contact()
{
  Contact c;
  // get contact info rom user
  c.setFirstName(PhoneBook::_get_user_field("First Name"));
  c.setLastName(PhoneBook::_get_user_field("Last Name"));
  c.setNickName(PhoneBook::_get_user_field("Nickname"));
  c.setPhoneNum(PhoneBook::_get_user_field("Phone Number"));
  c.setSecret(PhoneBook::_get_user_field("Darkest Secret"));
  // add contact to phone book
  _list[_i] = c;
  if (++_i >= PB_SIZE)
    _i = 0;
  if (_len < PB_SIZE)
    _len += 1;
  
}

void PhoneBook::_field_print(std::string label, std::string value)
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
  PhoneBook::_field_print("First Name: ", _list[i].getFirstName());
  PhoneBook::_field_print("Last Name: ", _list[i].getLastName());
  PhoneBook::_field_print("Nickame: ", _list[i].getNickName());
  PhoneBook::_field_print("Phone Number: ", _list[i].getPhoneNum());
  PhoneBook::_field_print("Darkest Secret: ", _list[i].getSecret());
  return (false);
}

void PhoneBook::show_contacts_table()
{
  std::cout << "|" << std::setw(10) << "index"
          << "|" << std::setw(10) << "firstName"
          << "|" << std::setw(10) << "lastName"
          << "|" << std::setw(10) << "nickname"
          << "|" << std::endl;
}

bool PhoneBook::isempty()
{
  return (!_len);
}

//TODO: remove me
void PhoneBook::display_contacts()
{
  for (int i =0; i < _len; i++)
  {
    PhoneBook::_field_print("First Name: ", _list[i].getFirstName());
    PhoneBook::_field_print("Last Name: ", _list[i].getLastName());
    PhoneBook::_field_print("Nickame: ", _list[i].getNickName());
    PhoneBook::_field_print("phone: ", _list[i].getPhoneNum());
    PhoneBook::_field_print("secret: ", _list[i].getSecret());
  }
}

