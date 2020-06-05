#include "presentationctl.hh"
using namespace std;

void PresentationCTL::usage ()
{
  cout << "USAGE:" << endl;
  cout << "This program receives three arguments. The first can be -c" << endl;
  cout << "if the desired operation is comressing or -x if the desired" << endl;
  cout << "operation is decompressing, the second one is the path to" << endl;
  cout << "the source file and the third is the path to the destination" << endl;
  cout << "file." << std::endl;
}

void PresentationCTL::inputFileError ()
{
  std::cout << "ERROR: error trying to open the input file." << std::endl;
}

void PresentationCTL::outputFileError ()
{
  std::cout << "ERROR: error trying to create the output file." << std::endl;
}
