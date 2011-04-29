#include "ExtendibleHash.h"



int Ehash(int value, int bits)
{
  return value >> (18 - bits) ;
} // Ehash()

ExtendibleHash::ExtendibleHash(const int & notFound, int b, int LSize) :
  bits(b), LeafSize(LSize)
{

} // ExtendibleHash()

void ExtendibleHash::insert(const int &object)
{

} // insert()


void ExtendibleHash::remove(const int &object)
{
}  // remove()


const int & ExtendibleHash::find(const int &object)
{
}  // find()



void ExtendibleHash::split(const int &object)
{
 
}  // split()


