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
  void insert(int value);
  void remove(int value);
  int find(int value);
  void split(int value);
    
}; //ExtendibleLeaf

#endif

