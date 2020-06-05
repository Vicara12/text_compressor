#ifndef DOMAINCTL_HH_
#define DOMAINCTL_HH_

#include "presentationctl.hh"
#include "persistencectl.hh"
#include "compressor.hh"
#include "extractor.hh"

/*

  This class is the one that handles the entire program, wich is structured in
  three layers,presentation, domain and persistence. In this case, this class
  also handles the domain layer.

*/
class DomainCTL
{
public:

  // execute the program
  static void execute (int argc, char** argv);

private:

  // checks the argument qty of the program and the first argument is correct
  static bool checkProgramArguments (int argc, char** argv);
};


#endif
