/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:55:34 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/28 15:00:28 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./container.hpp"

class PhoneBook {

  private:
    Contact _list[PB_SIZE];
    int _i;
    int _len;
    std::string _getUserField(std::string label);
    std::string _truncate(std::string str);
    void _fieldPrint(std::string label, std::string value);
    void _formatColumn(int index, std::string firstn, std::string lastn, std::string nickn);
    bool _isEmpty(const std::string str);
  public:
    PhoneBook();
    void add_new_contact();
    bool display_contact(int i); // if i == 0 return true, otherways false and display contact related to index if founded
    void show_contacts_table(); // search
    bool isempty();
};
#endif


