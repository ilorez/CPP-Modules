/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:57:22 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/29 12:57:24 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_HPP
#define HELPERS_HPP

#include "./Container.hpp"

enum t_type {
  TCHAR,
  TINT,
  TFLOAT,
  TDOUBLE,
  TPSEUDOF,
  TPSEUDOD
};


bool isValid(const std::string &s);

bool isChar(const std::string &s);

bool isInt(const std::string &s);

bool isFloat(const std::string &s);

t_type getType(const std::string &s);

void printChar(int c);

void printImpossible(int n);

bool getInt(const std::string &s, int &v);

bool getFloat(const std::string &s, float &v);

bool getDouble(const std::string &s, double &v);

#endif // !HELPERS_HPP
