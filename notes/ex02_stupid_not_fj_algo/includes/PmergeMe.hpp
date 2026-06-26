#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <sstream>
#include <sys/time.h>

template <template <typename, typename> class container,
          typename Alloc = std::allocator<int> >
class PmergeMe {
private:
  typedef typename Alloc::template rebind<std::pair<int, int> >::other PairAlloc;
  container<std::pair<int, int>, PairAlloc> _pairs;
  container<int, Alloc> _input;
  container<int, Alloc> _main_chain;
  container<int, Alloc> _pend_chain;
  container<int, Alloc> _jacobsthal_sq;
  int _straggler;
  struct timeval _start, _end;

public:
  PmergeMe() : _straggler(-1) {};

  ~PmergeMe() {};
  PmergeMe(const PmergeMe &copy) { *this = copy; };
  PmergeMe &operator=(const PmergeMe &copy) {
    if (this != &copy) {
      _straggler = copy._straggler;
    }
    return *this;
  };

  // member functions
  void validateInput(char **sequence) {
    int tmp_var;
    for (int i = 1; sequence[i]; i++) {
      std::stringstream ss(sequence[i]);
      ss >> tmp_var;
      if (ss.fail() || !ss.eof())
        throw(
            PmergeMeException("argumnet should be positive integer sequence."));
      if (tmp_var <= 0)
        throw(PmergeMeException("all number must be positive."));
      _input.push_back(tmp_var);
    }
  };

  void createPairList() {
    gettimeofday(&_start, NULL);
    if (_input.size() % 2 != 0)
      _straggler = _input.back();
    for (size_t i = 0; i < _input.size() - 1; i += 2) {
      // sort pair
      if (_input[i] > _input[i + 1])
        _pairs.push_back(std::make_pair(_input[i], _input[i + 1]));
      else
        _pairs.push_back(std::make_pair(_input[i + 1], _input[i]));
    }
  };

  void sortPairs() { std::sort(_pairs.begin(), _pairs.end()); };
  void setupChains() {

    if (!_pairs.size())
      return;
    // because its always b1 < a1 so we push it from start
    _main_chain.push_back(_pairs[0].second);
    for (size_t i = 0; i < _pairs.size(); i++) {
      _main_chain.push_back(_pairs[i].first);
      _pend_chain.push_back(_pairs[i].second);
    }
  };
  void generateJacobsthalSq() {
    container<int, Alloc> js;
    size_t current;
    js.push_back(1);
    js.push_back(1);
    js.push_back(3);

    // in case of there is just b1 b2 in pend chain
    if (_pend_chain.size() > 2)
      _jacobsthal_sq.push_back(3);
    if (_pend_chain.size() > 1)
      _jacobsthal_sq.push_back(2);
    for (size_t i = 3; i < _pend_chain.size(); i++) {
      // current = previous + 2 × (previous of the previous)
      current = js[i - 1] + 2 * js[i - 2];
      // for use later with next number in Jacob sequence
      js.push_back(current);
      // if found that next number in jacob sequence is large then
      // the number of elemenet we have in pend_chain we just start from
      // pend_chain size remember that the jacob sequence is used to get index,
      // no need for index that will not be used
      if (current > _pend_chain.size())
        current = _pend_chain.size();
      // we stop when we found "current" inside jacob arr
      // we can use find to do this
      // but we know also that the first element we will found is the element we
      // start counting down from it and that element is the js[-2] before last
      // element which is already stored in js
      while (current != static_cast<size_t>(*(js.end() - 2))) {
        _jacobsthal_sq.push_back(current--);
        if (_jacobsthal_sq.size() == _pend_chain.size() - 1)
          return;
      }
    }
  };

  void insertPends() {
    int bk;
    int ak;
    typename container<int, Alloc>::iterator ak_pos;
    typename container<int, Alloc>::iterator insert_pos;
    for (size_t i = 0; i < _jacobsthal_sq.size(); i++) {
      bk = _pend_chain[_jacobsthal_sq[i] - 1];
      ak = _pairs[_jacobsthal_sq[i] - 1].first;
      ak_pos = std::lower_bound(_main_chain.begin(), _main_chain.end(), ak);
      insert_pos = std::lower_bound(_main_chain.begin(), ak_pos + 1, bk);
      _main_chain.insert(insert_pos, bk);
    }
    if (_straggler != -1) {
      insert_pos =
          std::lower_bound(_main_chain.begin(), _main_chain.end(), _straggler);
      _main_chain.insert(insert_pos, _straggler);
    }
    // DONE
    gettimeofday(&_end, NULL);
  };

  void displayInterval(std::string container_name) {
    double elapsed =
        (_end.tv_sec - _start.tv_sec) * 1e6 + (_end.tv_usec - _start.tv_usec);
    std::cout << "Time to process a range of " << _input.size()
              << " elements with " << container_name << " : " << elapsed
              << " us" << std::endl;
  }

  void displayInput() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _input.size(); i++)
      std::cout << _input[i] << " ";
    std::cout << std::endl;
  };

  void displayMainChain() {

    std::cout << "After: ";
    for (size_t i = 0; i < _main_chain.size(); i++)
      std::cout << _main_chain[i] << " ";
    std::cout << std::endl;
  };

  void sort(char **sequence) {

    validateInput(sequence);
    createPairList();
    sortPairs();
    setupChains();
    generateJacobsthalSq();
    insertPends();
  };

  /*
    // debug
    void printAll() {
      std::cout << "=== Input ===" << std::endl;
      for (size_t i = 0; i < _input.size(); i++)
        std::cout << _input[i] << " ";
      std::cout << std::endl;
      if (_straggler != -1)
        std::cout << "=== Straggler: " << _straggler << " ===" << std::endl;
      std::cout << "=== Pairs ===" << std::endl;
      for (size_t i = 0; i < _pairs.size(); i++)
        std::cout << "[" << _pairs[i].first << ", " << _pairs[i].second << "] ";
      std::cout << std::endl;

      std::cout << "=== Main Chain ===" << std::endl;
      for (size_t i = 0; i < _main_chain.size(); i++)
        std::cout << _main_chain[i] << " ";
      std::cout << std::endl;

      std::cout << "=== Pend Chain ===" << std::endl;
      for (size_t i = 0; i < _pend_chain.size(); i++)
        std::cout << _pend_chain[i] << " ";
      std::cout << std::endl;

      std::cout << "=== Jacobsthal Sequence ===" << std::endl;
      for (size_t i = 0; i < _jacobsthal_sq.size(); i++)
        std::cout << _jacobsthal_sq[i] << " ";
      std::cout << std::endl;
    };

    */
  class PmergeMeException : public std::exception {
  private:
    std::string _msg;

  public:
    PmergeMeException(std::string msg) : _msg(msg) {};
    ~PmergeMeException() throw() {};
    const char *what() const throw() { return _msg.c_str(); };
  };
};
#endif
