#include "ExtendibleHash.h"
#include "ExtendibleLeaf.h"

ExtendibleLeaf::ExtendibleLeaf(int LSize)
{
  data = new int[LSize];
  LeafSize = LSize;
  count = 0;
}

bool ExtendibleLeaf::insert(ExtendibleLeaf ** dir, int object, int bits)
{
  if(count < LeafSize)
    {
      insertDriver(object);
      return NULL;
    }
  else
    {
      return split(dir, object, bits);
    }
}

void ExtendibleLeaf::insertDriver(int object)
{
  data[count] = object;
  count++;
}

void ExtendibleLeaf::remove(int object)
{
  for(int i = 0; i < count; i++)
    {
      if(data[i] == object)
	{
	  data[i] = data[count-1]; //assign new value
	  data[count-1] = 0; //zero old
	  count--;
	  i = count; //break loop (duplicates will stay!) 
	}
    }
  //note: if empty, just leave it be (no merge)
}

int ExtendibleLeaf::find(int object)
{
  for(int i = 0; i < count; i++)
    {
      if(data[i] == object)
	{
	  return object;
	}
    }
  return -1; //not found
}

int EHash(int value, int bits)
{
  return value >> (18 - bits);
} // Ehash()

//0 = good, 1 = split
bool ExtendibleLeaf::split(ExtendibleLeaf ** dir, int object, int bits) //pointer to new leaf
{
  int mark = EHash(object,bits);
  for(int i = 0; i < LeafSize; i++)
    {
      if(EHash(data[i],bits) != mark) //first value we can split
	{
	  int newmark = EHash(data[i],bits);
	  int val = data[i];
	  remove(val); //take it out
	  dir[newmark] = new ExtendibleLeaf(LeafSize);
	  dir[newmark]->insertDriver(val); //put it in
	  return NULL;
	}
    }
  return 1; //failed
}


