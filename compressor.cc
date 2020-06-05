#include "compressor.hh"

#include <iostream>

Algorithm* Compressor::instance = new Compressor();

bool pairComparator (const std::pair<char,int>& p1, const std::pair<char,int>& p2)
{
  return p1.second < p2.second;
}

void Compressor::execute (char* file_in, char* file_out)
{
  this->file_in.openFile(file_in, true);

  countChars();

  makeTree();

  this->file_in.closeFile();
}

Algorithm* Compressor::getInstance ()
{
  return Compressor::instance;
}

Compressor::Compressor ()
{
  // initialize the arrays with 0 and ""
  for (int i = 0; i < 128; i++) {
    char_counts[i] = 0;
    char_codes[i] = "";
  }
}

void Compressor::countChars ()
{
  while (not file_in.lastChar()) {
    char_counts[int(file_in.readChar())]++;
  }
}

void Compressor::makeTree ()
{
  std::list<std::pair<char,int>> char_qty;

  // make a list and fill it with the count of each character
  for (int i = 0; i < 128; i++)
    char_qty.push_back(std::make_pair(char(i), char_counts[i]));

  char_qty.sort(pairComparator);

  std::list<std::pair<char,int>>::iterator it = char_qty.begin();

  while (it != char_qty.end() and it->second == 0)
    it = char_qty.erase(it);


  for (it = char_qty.begin(); it != char_qty.end(); it++)
    std::cout << it->first << ": " << it->second << std::endl;
}
