#include <iostream>
using namespace std;

class Father
{
public:
  virtual Father* getInstance();
protected:
  static Father* instance;
};

class Son : public Father
{
public:
  static Father* getInstance ()
  {
    if (instance == 0)
      instance = new Son();

    return instance;
  }

private:
  Son();
};


int main ()
{
  Father* son = Son::getInstance();
}
