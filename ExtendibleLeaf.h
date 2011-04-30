#ifndef EXTENDIBLE_LEAF_H
#define EXTENDIBLE_LEAF_H

#include "ExtendibleHash.h"

class ExtendibleLeaf
{
  int LSize;
  int count;
  int *firstparent;

 public:
  ExtendibleLeaf(int LSize);
  void insert(int object);
  void remove(int object);
  int find(int object);
  int split(int object);
    
}; //ExtendibleLeaf

#endif

