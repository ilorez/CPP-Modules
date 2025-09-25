/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:52:31 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/25 18:41:23 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {

  private:
    std::string _firstn, _lastn, _nickname, _num, _secret;
  public:
    //getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNum() const;
    std::string getSecret() const;

    //setters
    void setFirstName(std::string value);
    void setLastName(std::string value);
    void setNickName(std::string value);
    void setPhoneNum(std::string value);
    void setSecret(std::string value);

};

#endif
