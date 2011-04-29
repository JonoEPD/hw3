#ifndef EXTENDIBLE_HASH_H
  #define EXTENDIBLE_HASH_H


class ExtendibleHash
{
//  ExtendibleLeaf  **Directory;
  int bits;
  int size;
  int LeafSize;

public:
  ExtendibleHash(const int & notFound, int s, int LSize = 2);
  void insert(const int &object);
  void remove(const int &object);
  const int & find(const int &object);
  void split(const int &object);
  int GetBits()const {return bits;}

}; // class ExtendibleHashing

#include "ExtendibleHash.cpp"

#endif

