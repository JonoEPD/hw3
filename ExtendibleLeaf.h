#ifndef EXTENDIBLE_LEAF_H
#define EXTENDIBLE_LEAF_H

#include "ExtendibleHash.h"

class ExtendibleLeaf
{
  int LeafSize;
  int count;
  int *data;

 public:
  ExtendibleLeaf(int LSize);
  void insert(int object);
  void remove(int object);
  int find(int object);
  void split(int object);
    
}; //ExtendibleLeaf

#endif

