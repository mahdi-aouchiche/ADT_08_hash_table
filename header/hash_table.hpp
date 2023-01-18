#ifndef __HASH_TABLE_HPP__
#define __HASH_TABLE_HPP__

#include <string>
#include <list>
#include <iostream>
#include "word_entry.hpp"
using namespace std;

class HashTable 
{
  private:
	list<WordEntry> *hashTable;
	int size;

  public:
	HashTable(int);
	bool contains(const string &);
	double getAverage(const string &);
	void put(const string &, int);
 
  private:
	int computeHash(const string &);
};

#endif  //__HASH_TABLE_HPP__
