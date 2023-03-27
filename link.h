#ifndef LINK_H
#define	LINK_H

#include <cstdlib>

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Singly linked list node
template <typename E> class Link {
private:
    int accesses;

public:
  E element;      // Value for this node
  Link *next;        // Pointer to next node in list
  // Constructors
  Link(const E& elemval, Link* nextval =NULL, int acc =0)
  {
      element = elemval;  next = nextval; accesses = acc;
  }
  Link(Link* nextval =NULL) { next = nextval; }

  // new stuff
  // new accesses member to make count easier :)
  int getAccess() const
  {
      return accesses;
  }

  // increments accesses
  void incrementA()
  {
      accesses++;
  }

  // setters
  void setAccess(int a)
  {
      if (a < 0)
          accesses = 0;
      else
          accesses = a;
  }

};

#endif