#include "../header/word_entry.hpp"

/* 
  WordEntry Constructor
  input: the string text and the intial score.
  The text should be assigned to word 
  & numAppearances should be set to 1 here.
*/
WordEntry::WordEntry(const string &text, int score)
: word(text), numAppearances(1), totalScore(score) {}

/* 
  input: a new score for a word that is already in the hash table.
  Function should increase total score by s 
  & also should increase numAppearances.
*/
void WordEntry::addNewAppearance(int s) {
	this->totalScore += s;
	++this->numAppearances;
}

/*
  This accessor function is needed particularly in 
  the HashTable code to get the word to be used for 
  the hash value.  
*/
const string & WordEntry::getWord() {
    return this->word;
}

/* 
  Returns the average score of the word based on 
  totalScore and numAppearances.
  Note: the typecasting which turns one of the integers
  to a double is necessary to avoid integer division.
*/
double WordEntry::getAverage() {
	return static_cast<double>(this->totalScore) / this->numAppearances;
}