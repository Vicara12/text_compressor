#ifndef COMPRESSOR_HH_
#define COMPRESSOR_HH_

#include "algorithm.hh"
#include "chartree.hh"
#include "persistencectl.hh"
#include <list>


// function used to sort the list of characters
bool pairComparator (const std::pair<char,int>& p1, const std::pair<char,int>& p2);


class Compressor : public Algorithm
{
public:

  // execute the compression algorithm
  void execute (char* file_in, char* file_out) override;

  // get a pointer to the only instance of the program
  static Algorithm* getInstance ();

private:

  PersistenceCTL file_in, file_out; // objects for the in and out files
  int char_counts [128];            // array with the count of every character
  CharTree tree;                    // tree object with the characters
  std::string char_codes [128];     // array with the encoded characters

  static Algorithm* instance;   // pointer to the only instance of the object

  // private constructor to initialize the parameters
  Compressor ();

  // fill the counting vector of characters
  void countChars ();

  // bouild the compression trees
  void makeTree ();

  // get the character encodings for the tree
  void getCharEncondings ();

  // write the encodings and the data to the file
  void compressFile ();

  // get tree string
  std::string getTreeString ();

};


#endif
