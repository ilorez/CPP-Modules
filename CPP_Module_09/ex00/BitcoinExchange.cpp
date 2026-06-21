/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:03:32 by znajdaou          #+#    #+#             */
/*   Updated: 2026/06/21 16:57:07 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/BitcoinExchange.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <iostream>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
  *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
  if (this != &copy)
  {
    _input_file = copy._input_file;
  }
  return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

bool BitcoinExchange::isValidDate(const std::string &date) const {
  // date = 2026-02-12
  if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    throw InvalidDateException();
  std::istringstream year(date.substr(0,4));
  std::istringstream month(date.substr(5, 2));
  std::istringstream day(date.substr(8,2));

  int y, m, d;
  if (!(year >> y) || !year.eof())
    return false;
  if (!(month >> m) || !month.eof())
    return false;
  if (!(day >> d) || !day.eof())
    return false;
  if (m < 1 || m > 12 || d < 1 || y < 0)
    return false;
  int maxday;
  switch (m)
  {
    case 2:
      maxday = 28;
      if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
        maxday = 29;
      break;
    case 4: case 6: case 9: case 11: maxday = 30; break;
    default: maxday = 31; break;
  }
  return d <= maxday;
}

double BitcoinExchange::getEchangeRate(const std::string &date) const{
  std::map<std::string, double>::const_iterator it = _db.lower_bound(date); 
  if (it != _db.end() && it->first == date)
    return it->second;
  else if (it == _db.begin())
    throw InvalidDateException();
  --it;
  return it->second;
}

// member functions
void BitcoinExchange::readInput(const char *path) 
{
  std::ifstream read(path);
  if (!read.is_open())
    throw CantReadDBException(); 
  std::string line;
  std::getline(read, line);
  if (line != "date | value")
    throw InvalidHeaderException();
  std::pair<std::string, double> pair;
  while (std::getline(read, line))
  {
    try {
      if (line.size() < 14)
        throw BadInputException(line);
      pair = getPair(line, 3);
      if (!isValidDate(pair.first))
        throw InvalidDateException();
      if (pair.second < 0)
        throw NotPositiveNumberException();
      if (pair.second > 1000)
        throw TooLargeNumberException();
      double exchange_rate = getEchangeRate(pair.first);
      double re = pair.second * exchange_rate;
      std::cout << pair.first << " => "
                << pair.second << " = "
                << re
                << std::endl;
    } catch (std::exception &e)
    {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
  read.close();
}

BitcoinExchange::t_pair BitcoinExchange::getPair(std::string line, int del_size)
{
  std::string date = line.substr(0, 10);
  std::istringstream iss(line.substr(10 + del_size));
  double value;
  if (!(iss >> value))
    throw BadInputException(line);
  return std::make_pair(date, value);
}

// read databse
void BitcoinExchange::readDb()
{
  std::ifstream read(DB_FILE_PATH);
  if (!read.is_open())
    throw CantReadDBException(); 
  std::string line;
  std::getline(read, line);
  // skip first line
  while (std::getline(read, line))
    _db.insert(getPair(line, 1));
  read.close();
}

// exceptions
const char* BitcoinExchange::InvalidDateException::what() const throw(){
  return "invalid date input.";
}

const char* BitcoinExchange::CantReadDBException::what() const throw(){
  return "Can't read databse.";
}

const char* BitcoinExchange::CouldNotOpenFileException::what() const throw(){
  return "could not open file.";
}

const char* BitcoinExchange::TooLargeNumberException::what() const throw(){
  return "too large a number.";
}

const char* BitcoinExchange::NotPositiveNumberException::what() const throw(){
  return "not a positive number.";
}

const char* BitcoinExchange::InvalidHeaderException::what() const throw(){
  return "invalid header, the input data should be on format of date | value, the parsing is so strict sorry :<";
}

const char* BitcoinExchange::BadInputException::what() const throw(){
  _msg = "bad input => " + _txt;
  return (_msg.c_str());
}

BitcoinExchange::BadInputException::~BadInputException() throw() {}
BitcoinExchange::BadInputException::BadInputException(const std::string &txt) :_txt(txt){}


