#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <sys/time.h>

template <template <typename, typename> class container, typename Alloc = std::allocator<int> >
class PmergeMe {
  private:
    container<std::pair<int, int>, Alloc > _pairs;
    container<int, Alloc> _input;
    container<int, Alloc> _main_chain;
    container<int, Alloc> _pend_chain;
    container<int, Alloc> _jacobsthal_sq;
    int _straggler;
	struct timeval _start, _end;

  public:
    PmergeMe(): _straggler(-1)
	{
		gettimeofday(&_start, NULL);
	};

    ~PmergeMe(){};
    PmergeMe(const PmergeMe& copy){*this = copy;};
    PmergeMe& operator=(const PmergeMe& copy){
  if (this != &copy)
  {
    _straggler = copy._straggler;
  }
  return *this;
}
;

    // member functions
    void validateInput(const char* sequence);
    void createPairList();
    void sortPairs();
    void setupChains();
    void generateJacobsthalSq();
    void insertPends();
	void displayInfo();

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
