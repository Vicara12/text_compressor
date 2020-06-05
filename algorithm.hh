#ifndef ALGORITHM_HH_
#define ALGORITHM_HH_

/*

  Abstract class for the compression and extraction algorithms.

*/
class Algorithm
{
public:

  //  function to execute the corresponding algorithm
  virtual void execute (char* file_in, char* file_out) = 0;

  //  get a pointer to the only instance of the corresponding algorithm object
  Algorithm* getInstance ();
};


#endif
