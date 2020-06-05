#include "persistencectl.hh"

#include <iostream>
using namespace std;

PersistenceCTL::PersistenceCTL ()
{
  file = -1;
  bit_ptr = 8;
  ch = -1;
  file_opened = false;
  opened_read = false;
}

void PersistenceCTL::openFile (char* path, bool read)
{
  if (read) {
    file = open(path, O_RDONLY);

    if (file == -1)
      throw FileCouldNotBeOpen();

    opened_read = true;
  }
  else {
    file = open(path, O_WRONLY | O_CREAT, 0644);

    if (file == -1)
      throw FileCouldNotBeCreated();

    opened_read = false;
  }

  file_opened = true;
  bit_ptr = 8;
}

void PersistenceCTL::closeFile ()
{
  if (not file_opened)
    throw NoOpenFile();

  close(file);

  bit_ptr = 8;
  file_opened = false;
}

char PersistenceCTL::readChar ()
{
  if (not file_opened)
    throw NoOpenFile();
  if (not opened_read)
    throw WriteFile();

  char c;
  bit_ptr = 0;


  if (read(file, &c, 1) == 0)
    throw ReachedEOF();


  return c;
}

bool PersistenceCTL::readBit ()
{
  if (not file_opened)
    throw NoOpenFile();
  if (not opened_read)
    throw WriteFile();

  if (bit_ptr >= 8) {
    ch = readChar();
    bit_ptr = 0;
  }

  bool bit = (ch >> bit_ptr) & 1;
  bit_ptr++;

  return bit;
}

bool PersistenceCTL::lastChar ()
{
  if (not file_opened)
    throw NoOpenFile();
  if (not opened_read)
    throw WriteFile();

  char c;
  bool last = (read(file, &c, 1) == 0);

  lseek(file, -1, SEEK_CUR);

  return last;
}

void PersistenceCTL::writeChar (char c)
{
  if (not file_opened)
    throw NoOpenFile();
  if (opened_read)
    throw ReadFile();

  if (write(file, &c, 1) == -1)
    throw ErrorWritingToFile();
}
