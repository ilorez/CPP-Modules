
#include "./includes/BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <utility>

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
    pair = getPair(line, 3);
    //checkDate(pair.first);
    if (pair.second < 0)
      throw NotPositiveNumberException();
    if (pair.second > 1000)
      throw TooLargeNumberException();
  }
  read.close();

}

t_pair BitcoinExchange::getPair(std::string line, int del_size)
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


