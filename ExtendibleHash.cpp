#include "ExtendibleHash.h"
#include "ExtendibleLeaf.h"

int pow(int a, int b) //integer power a^b
{
  int power = 1;
  for(int i = 0; i < b; i++)
    {
      power *= a;
    }
  return power;
}

int Ehash(int value, int bits)
{
  return value >> (18 - bits) ;
} // Ehash()

ExtendibleHash::ExtendibleHash(const int & notFound, int b, int LSize) :
  bits(b), LeafSize(LSize)
{
  directory = new ExtendibleLeaf *[pow(2,b)];
} // ExtendibleHash()

void ExtendibleHash::insert(const int &object)
{
  
} // insert()


void ExtendibleHash::remove(const int &object)
{
}  // remove()


const int ExtendibleHash::find(const int &object)
{
  return 0;
}  // find()



void ExtendibleHash::split(const int &object)
{
 
}  // split()
