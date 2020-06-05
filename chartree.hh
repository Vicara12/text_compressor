#ifndef CHARTREE_HH_
#define CHARTREE_HH_

/*

  Struct that holds the data of the tree

*/
struct Node
{
  bool is_char;
  char c;

  Node *previous, *right, *left;
};


/*

  This class forms the character tree that will be used to encript the
  characters.

*/
class CharTree
{
public:

  // default constructor, should not be used
  CharTree();

  // chaaracter node constructor
  CharTree (char c);

  // non character node constructor
  CharTree (CharTree& left, CharTree& right);

  // move node pointer to the right
  void ptrRight ();

  // move node pointer to the left
  void ptrLeft ();

  // move node pointer to the previous note
  void ptrBack ();

  // move the node pointer back to the root node
  void ptrToRoot ();

  // tells if the node pointed by the node pointer is a character
  bool isChar ();

  // if the node pointed by the node pointer is a char, it's value is returned
  char getChar ();

  // when the non character constructor is used, the node is removed. This
  // function tells if the current tree has a node
  bool hasRoot ();

  // returns whether the node pointer is at the root
  bool ptrAtRoot ();

private:
  Node* node_ptr;
  Node* root;

  // clear the root pointer adn node pointer
  void deleteRootNode ();
};

#endif
