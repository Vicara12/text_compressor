#ifndef EXCEPTIONS_HH_
#define EXCEPTIONS_HH_

#include <exception>

// exception used in PersistenceCTL
struct EndOfFile : public std::exception
{
  const char* what () const throw ()
  {
    return "the reader has reached the end of the file";
  }
};

// exception used in PersistenceCTL
struct FileCouldNotBeOpen : public std::exception
{
  const char* what () const throw ()
  {
    return "the file could not be open";
  }
};

// exception used in PersistenceCTL
struct FileCouldNotBeCreated : public std::exception
{
  const char* what () const throw ()
  {
    return "the file could not be created";
  }
};

// exception used in PersistenceCTL
struct ReachedEOF : public std::exception
{
  const char* what () const throw ()
  {
    return "the end of the file has been reached";
  }
};

// exception used in PersistenceCTL
struct NoOpenFile : public std::exception
{
  const char* what () const throw ()
  {
    return "there isn't any opened file";
  }
};

// exception used in PersistenceCTL
struct WriteFile : public std::exception
{
  const char* what () const throw ()
  {
    return "the file is open in write mode";
  }
};

// exception used in PersistenceCTL
struct ReadFile : public std::exception
{
  const char* what () const throw ()
  {
    return "the file is open in read mode";
  }
};

// exception used in PersistenceCTL
struct ErrorWritingToFile : public std::exception
{
  const char* what () const throw ()
  {
    return "an error ocurred while writing character to the file";
  }
};

#endif
