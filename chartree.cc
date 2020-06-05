#include "chartree.hh"

CharTree::CharTree () {}

CharTree::CharTree (char c)
{
  root = new Node();
  node_ptr = root;

  // asign the data
  root->is_char = true;
  root->c = c;
  root->previous = 0;
  root->right = 0;
  root->left = 0;
}

CharTree::CharTree (CharTree& left, CharTree& right)
{
  root = new Node();
  node_ptr = root;

  // asign the data
  root->is_char = false;
  root->previous = 0;
  root->left = left.root;
  root->right = right.root;

  // set the previous of right and left to the root node
  left.root->previous = root;
  right.root->previous = root;

  // remove right and left
  left.deleteRootNode();
  right.deleteRootNode();
}

void CharTree::ptrRight ()
{
  node_ptr = node_ptr->right;
}

void CharTree::ptrLeft ()
{
  node_ptr = node_ptr->left;
}

void CharTree::ptrBack ()
{
  node_ptr = node_ptr->previous;
}

bool CharTree::isChar ()
{
  return node_ptr->is_char;
}

char CharTree::getChar ()
{
  return node_ptr->c;
}

bool CharTree::hasRoot ()
{
  return root == 0;
}

bool CharTree::ptrAtRoot ()
{
  return node_ptr == root;
}

void CharTree::deleteRootNode ()
{
  node_ptr = 0;
  root = 0;
}
