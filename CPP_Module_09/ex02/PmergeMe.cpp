/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:55:39 by znajdaou          #+#    #+#             */
/*   Updated: 2026/06/23 23:23:37 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"
#include <algorithm>
#include <sstream>
#include <utility>
#include <vector>
#include <iostream>

// orthx conanical form
PmergeMe::PmergeMe(): _straggler(-1){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& copy){*this = copy;}
PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
  if (this != &copy)
  {
    _straggler = copy._straggler;
  }
  return *this;
}

// member functions
void PmergeMe::validateInput(const char* sq)
{
  int tmp_var;
  std::stringstream ss(sq);
  while (!ss.eof())
  {
    ss >> tmp_var;
    if (ss.fail())
      throw (PmergeMeException("argumnet should be positive integer sequence."));
    if (tmp_var < 0)
      throw (PmergeMeException("all number must be positive."));
    _input.push_back(tmp_var);
  }
}
void PmergeMe::createPairList() {
  
  if (_input.size() % 2 != 0)
    _straggler = _input.back();
  for (size_t i = 0; i < _input.size() -1  ; i+=2)
  {
    // sort pairs
    if (_input[i] > _input[i+1])
      _pairs.push_back(std::make_pair(_input[i], _input[i+1]));
    else
      _pairs.push_back(std::make_pair(_input[i+1], _input[i]));
  }
}

void PmergeMe::sortPairs(){
  std::sort(_pairs.begin(), _pairs.end());
}

void PmergeMe::setupChains(){

  if (!_pairs.size())
    return ;
  // because its always b1 < a1 so we push it from start
  _main_chain.push_back(_pairs[0].second);
  for (size_t i = 0; i < _pairs.size(); i++)
  {
      _main_chain.push_back(_pairs[i].first);
      _pend_chain.push_back(_pairs[i].second);
  }
  // TODO: is pushing straggler now make probleme
  //if (_straggler != -1)
   // _pend_chain.push_back(_straggler);
}

/*void PmergeMe::generateJacobsthalSq(){
  _jacobsthal_sq.push_back(3);
  _jacobsthal_sq.push_back(5);
  for (size_t i = 2; i < _input.size(); i++)
  {
    // current = previous + 2 × (previous of the previous)
    int current = _jacobsthal_sq[i-1] + 2 * _jacobsthal_sq[i-2];
    _jacobsthal_sq.push_back(current);
  }
}*/

// Important Note:
// the Jacobsthal sequence give you the number of item no the index
// so its technically start from 1 not 0
// we do same here
void PmergeMe::generateJacobsthalSq(){
  std::vector<int> js;
  size_t current;
  js.push_back(1);
  js.push_back(1);
  js.push_back(3);

  // in case of there is just b1 b2 in pend chain
  if (_pend_chain.size() > 2)
    _jacobsthal_sq.push_back(3);
  if (_pend_chain.size() > 1)
    _jacobsthal_sq.push_back(2);
  for (size_t i = 3; i < _pend_chain.size() ; i++)
  {
    // current = previous + 2 × (previous of the previous)
    current = js[i-1] + 2 * js[i-2];
    // for use later with next number in Jacob sequence
    js.push_back(current);
    // if found that next number in jacob sequence is large then 
    // the number of elemenet we have in pend_chain we just start from pend_chain size
    // remember that the jacob sequence is used to get index, 
    // no need for index that will not be used
    if (current > _pend_chain.size())
      current = _pend_chain.size();
	// we stop when we found "current" inside jacob arr
	// we can use find to do this
	// but we know also that the first element we will found is the element we start counting down from it
	// and that element is the js[-2] before last element which is already stored in js vector
    while (current != static_cast<size_t>(*(js.end() -2) ))
    {
      _jacobsthal_sq.push_back(current--);
      if (_jacobsthal_sq.size() == _pend_chain.size() - 1)
        return;
    }
  }
}

void PmergeMe::insertPends() {
  int bk;
  int ak;
  std::vector<int>::iterator ak_pos;
  std::vector<int>::iterator insert_pos;
  for (size_t i = 0; i < _jacobsthal_sq.size(); i++)
  {
    bk = _pend_chain[_jacobsthal_sq[i] - 1];
    ak = _pairs[_jacobsthal_sq[i]-1].first;
    ak_pos = std::lower_bound(_main_chain.begin(), _main_chain.end(), ak);
    insert_pos = std::lower_bound(_main_chain.begin(), ak_pos + 1, bk);
    _main_chain.insert(insert_pos, bk);
  }
  if (_straggler != -1)
  {
    insert_pos = std::lower_bound(_main_chain.begin(), _main_chain.end(), _straggler);
    _main_chain.insert(insert_pos, _straggler);
  }
}

// exception
PmergeMe::PmergeMeException::~PmergeMeException() throw() {}
PmergeMe::PmergeMeException::PmergeMeException(std::string msg): _msg(msg){}
const char * PmergeMe::PmergeMeException::what() const throw() {
  return (_msg.c_str());
}


// debug
void PmergeMe::printAll()
{
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



    
}
