#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <utility>
#include <vector>
class PmergeMe {
  private:
    std::vector<std::pair<int, int> > _pairs;
    std::vector<int> _input;
    std::vector<int> _main_chain;
    std::vector<int> _pend_chain;
    std::vector<int> _jacobsthal_sq;
    int _straggler;
  public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& copy);
    PmergeMe& operator=(const PmergeMe& copy);

    // member functions
    void validateInput(const char* sequence);
    void createPairList();
    void sortPairs();
    void setupChains();
    void generateJacobsthalSq();
    void insertPends();

    // debug
    void printAll();


    class PmergeMeException: public std::exception {
      private:
        std::string _msg;
      public:
        PmergeMeException(std::string msg);
        ~PmergeMeException() throw();
        const char* what() const throw();
    };
};
#endif
