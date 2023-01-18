#include "hash_table.cpp"
#include "word_entry.cpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
  string line;    
  int score;
  string message = " ";
	
  /* Open input file */
  ifstream myfile("movieReviews.txt");
  if (myfile.fail()) {
    cout << "could not open file 'movieReviews.txt'." << endl;
	  exit(1);
  }
	
  /* Create hash table using the given movie reviews */
  HashTable table(20071);
  int len = 0;
  string sub;

  while (!myfile.eof()) {
    myfile >> score;     // get score
	  myfile.get();        // get blank space
	  getline(myfile, line);
	  len = line.size();
	  while(len > 0) {     // identify all individual strings
	    len = line.find(" ");
	    if (len > 0) {
	      sub = line.substr(0, len);
	      line = line.substr(len + 1, line.size());
	    }
	    else {
	      sub = line.substr(0, line.size() - 1);
	    }
	    table.put(sub, score); // insert string with the score
	  }
  }
	
  /*
    After data is entered in hash function
    prompt user for a new movie review
  */
  double sum = 0;
  int count  = 0;
  double sentiment = 0.0;
    
  while(message.length() > 0) {
    cout << "enter a review -- Press return to exit: " << endl;
    getline(cin, message);
    
    size_t len = message.size();
    // get each individual word from the input
    while(len != string::npos) {
      string sub;
      len = message.find(" ");
      if (len != string::npos) {
        sub = message.substr(0, len);
        message = message.substr(len + 1, message.size());
      }
      else {
        sub = message;
      }
      // Calculate the score of each word
      sum += table.getAverage(sub);
      ++count;
    }
	
    if (message.size() > 0) {
   	  sentiment = sum / count;
      cout << "The review has an average value of " << sentiment << endl;
	    if (sentiment >= 3.0) {
	      cout << "Positive Sentiment" << endl;
	    }
	    else if (sentiment >= 2.0) {
	      cout << "Somewhat Positive Sentiment" << endl;
	    }
	    else if (sentiment >= 1.0) {
	   	  cout << "Somewhat Negative Sentiment" << endl;
	    }
	    else {
	   	  cout << "Negative Sentiment" << endl;
	    }
	    cout << endl;
	  }
    /* Reset count and sum */
    sum = 0;
    count = 0;
  }
	
  return 0;
}