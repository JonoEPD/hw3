#ifndef EXTENDIBLE_HASH_H
#define EXTENDIBLE_HASH_H

#include "ExtendibleLeaf.h"
#include "ExtendibleLeaf.cpp"

class ExtendibleHash
{
  ExtendibleLeaf** directory;
  int bits;
  int size;
  int LeafSize;
  int notfound;

public:
  ExtendibleHash(const int & notFound, int s, int LSize = 2);
  void insert(const int &object);
  void remove(const int &object);
  const int find(const int &object);
  void split(const int &object);
  int GetBits()const {return bits;}

}; // class ExtendibleHashing

#include "ExtendibleHash.cpp"

#endif

