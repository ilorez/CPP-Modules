#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#define DB_FILE_PATH "./data.csv" // the data.csv file should always be valid

class BitcoinExchange {
  private:
    std::map<std::string, double> _db;
    std::string _input_file;
  public:
    typedef std::pair<std::string, double> t_pair;
    // orthx
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& copy);
    BitcoinExchange& operator=(const BitcoinExchange& copy);
    ~BitcoinExchange();

    void readDb();
    void readInput(const char* path);
    // this function read single line check if valid and throw error
    t_pair readLine(); 
    // ("2011-01-03 | 3.111", 3) ==> {first: "2011-01-03", second: 3.111}
    t_pair getPair(std::string line, int del_size);
    bool isValidDate(const std::string &date) const;
    double getEchangeRate(const std::string &date) const;

    // exceptions
    class InvalidDateException: public std::exception {
      private:
        std::string _txt;
        mutable std::string _msg;
      public:
        InvalidDateException(const std::string &text);
        ~InvalidDateException() throw();
        const char* what() const throw();
    };

    class CantReadDBException: public std::exception {
      public:
        const char* what() const throw();
    };

    class CouldNotOpenFileException: public std::exception {
      public:
        const char* what() const throw();
    };

    class TooLargeNumberException: public std::exception {
      public:
        const char* what() const throw();
    };

    class NotPositiveNumberException: public std::exception {
      public:
        const char* what() const throw();
    };

    class InvalidHeaderException: public std::exception {
      public:
        const char* what() const throw();
    };

    class BadInputException: public std::exception {
      private:
        std::string _txt;
        mutable std::string _msg; 
      public:
        BadInputException(const std::string &text);
        ~BadInputException() throw();
        const char* what() const throw();
    };




};
#endif
