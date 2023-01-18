#include "../header/hash_table.hpp"
#include "../header/word_entry.hpp"

/* 
  HashTable constructor.
  input s is the size of the array
  set s to be size
  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {
  this->size = s;
  hashTable = new list<WordEntry>[this->size];   
}

/* 
  Return an integer based on the input string
  used for index into the array in hash table
  be sure to use the size of the array to 
  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string &s) {
  int k;                        // array element    
  unsigned x = 4;               // multiplier 4 
  unsigned hash = 0;            // string hash value
  
  for(unsigned i = 0; i < s.size(); ++i) {
    hash += s[i] * (x << i) ;   // value of all letters multiplied 
  }
  
  k = hash % this->size;  
  return k;
}

/* 
  input: string word and int score to be inserted
  First, look to see if word already exists in hash table
  if so, addNewAppearence with the score to the WordEntry
  if not, create a new Entry and push it on the list at the
  appropriate array index
*/
void HashTable::put(const string &s, int score) {

  int k = computeHash(s);   // find the bucket of the word

  // look to see if the word already exists in hash table  
  if(contains(s)) {
    // find the word in the list 
    for(auto i = hashTable[k].begin(); i !=  hashTable[k].end(); ++i) { 
      if(i->getWord() == s) {        
        i->addNewAppearance(score);     // update word's score and appearance
      }  
    }

  } else {   // deal with collisions by adding them to the list
    WordEntry newWord(s, score);              // create a new entry object
    this->hashTable[k].push_back(newWord);    // push it to the list 
  }
}

/* 
  input: string word 
  output: the result of a call to getAverage()
  from the WordEntry.
  Must first find the WordEntry in the hash table
  then return the average.
  If not found, return the value 2.0 (neutral result).
*/
double HashTable::getAverage(const string &s) {
  double average; 
  if( !contains(s) ) {
    average = 2.0;                  // word not in the table 
  } else {
    int k = this->computeHash(s);   // find the word's bucket

    // find the word in the list 
    for(auto i = hashTable[k].begin(); i !=  hashTable[k].end(); ++i) { 
      if(i->getWord() == s) {    
        average = i->getAverage();   // get the average score 
      }  
    }
  }
  return average; 
}

/* 
  input: string word
  output: true if word is in the hash table
  false if word is not in the hash table
*/
bool HashTable::contains(const string &s) {
  int k = this->computeHash(s);       // find the bucket in the array

  if(! this->hashTable[k].empty()) {  // check if list is not empty 

    // go through the list (use list<WordEntry> :: iterator i or use auto)
    for(auto i = hashTable[k].begin(); i !=  hashTable[k].end(); ++i) { 
      if(i->getWord() == s) {        
        return true;
      }  
    }
  } 

  return false; // string not in the list 
}