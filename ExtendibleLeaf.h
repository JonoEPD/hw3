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
  //NULL = we're good, //1 = dirsplit
  bool insert(ExtendibleLeaf ** dir, int value, int bits); 
  void insertDriver(int value);
  void remove(int value);
  int find(int value);
  bool split(ExtendibleLeaf **, int value, int bits);
  
}; //ExtendibleLeaf

#include "ExtendibleLeaf.cpp"

#endif

