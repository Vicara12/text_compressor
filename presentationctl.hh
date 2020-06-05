#ifndef PRESENTATIONCTL_HH_
#define PRESENTATIONCTL_HH_

#include <iostream>

/*
  This class handles the entire presentation layer, and basically is the one in
  charge of displaying messages to the user. It is called from DomainCTL.
*/
class PresentationCTL
{
public:
  
  // displays the list of parameters of the program
  static void usage ();

  // displays the error for the input file error
  static void inputFileError ();

  // displays the error for the output file error
  static void outputFileError ();
};


#endif
