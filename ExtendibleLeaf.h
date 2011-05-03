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
  ExtendibleLeaf * insert(ExtendibleLeaf ** dir, int value, int bits);
  void remove(int value);
  int find(int value);
  ExtendibleLeaf * split(ExtendibleLeaf ** dir, int value, int bits);
  
}; //ExtendibleLeaf

#include "ExtendibleLeaf.cpp"

#endif

