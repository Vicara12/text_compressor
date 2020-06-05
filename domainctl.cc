#include "domainctl.hh"

void DomainCTL::execute (int argc, char** argv)
{
  if (not checkProgramArguments(argc, argv)) {
    PresentationCTL::usage();
    return;
  }

  Algorithm* algorithm;

  if (argv[1][1] == 'c') algorithm = Compressor::getInstance();
  else algorithm = Compressor::getInstance();

  algorithm->execute(argv[2], argv[3]);
}

bool DomainCTL::checkProgramArguments (int argc, char** argv)
{
  // check argument qty is correct
  if (argc != 4)
    return false;

  // check first argument is correct
  if (argv[1][0] != '-' or
      (argv[1][1] != 'c' and argv[1][1] != 'x') or
      argv[1][2] != 0)
    return false;

  return true;
}
