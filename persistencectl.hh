#ifndef PERSISTENCECTL_HH_
#define PERSISTENCECTL_HH_


#include "exceptions.hh"
#include "domainctl.hh"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

/*

  This class handles and reads the files.

*/
class PersistenceCTL
{
public:

  PersistenceCTL();

  // open the file in the selected path
  // can throw: FileCouldNotBeOpen, FileCouldNotBeCreated
  void openFile (char* path, bool read);

  // close the oppened file
  // can throw: NoOpenFile
  void closeFile ();

  // get the next character in the file
  // can throw: ReachedEOF, NoOpenFile, WriteFile
  char readChar ();

  // get the next bit of hte file
  // can throw: ReachedEOF, NoOpenFile, WriteFile
  bool readBit ();

  // tells whether this is the last character in the file
  // can throw: NoOpenFile, WriteFile
  bool lastChar ();

  // returns wether the EOF has been reached
  // can throw: NoOpenFile, WriteFile
  bool reachedEOF ();

  // writes the given character into the file
  // can throw: NoOpenFile, ReadFile
  void writeChar (char c);

private:

  int file;
  int bit_ptr;
  bool file_opened;
  bool opened_read;
  char ch;

};


#endif
