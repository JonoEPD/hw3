//Jonathan Hollenbeck

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
  return value >> (18 - bits);
} // Ehash()

ExtendibleHash::ExtendibleHash(const int & notFound, int b, int LSize) :
  bits(b), LeafSize(LSize)
{
  int directs = pow(2,b);
  directory = new ExtendibleLeaf* [directs];
  directory[0] = new ExtendibleLeaf(LSize);
  for(int i = 0; i < directs; i++) //easiest way, initially have everything point to an empty leaf
    {
      directory[i] = directory[0];
    }
  notfound = notFound;
} // ExtendibleHash()

void ExtendibleHash::insert(const int &object)
{
  int bin = Ehash(object,bits);
  int fail = directory[bin]->insert(directory, object, bits); 
  if(fail == true)
    {
      split(object);
      insert(object);
    }
} // insert()

void ExtendibleHash::remove(const int &object)
{
  int bin = Ehash(object,bits);
  directory[bin]->remove(object);
}  // remove()


const int ExtendibleHash::find(const int &object)
{
  int bin = Ehash(object,bits);
  int look = directory[bin]->find(object); 
  if(look == -1)
    return notfound; //key for "not found"
  else
    return look;
}  // find()


void ExtendibleHash::split(const int &object) //called iff lsplit fail
{
  int direct = pow(2,bits);
  int ndirect = pow(2,bits+1);
  ExtendibleLeaf ** newdir = new ExtendibleLeaf* [ndirect];
  for(int i = 0; i < direct; i++)
    {
      newdir[2*i] = directory[i]; //simply double all leaves
      newdir[2*i+1] = directory[i];
    }
  ExtendibleLeaf ** tmpdir = directory;
  directory = newdir; //swap
  delete tmpdir;
  bits++;
}  // split()
