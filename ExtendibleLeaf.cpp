#include "ExtendibleHash.h"
#include "ExtendibleLeaf.h"

ExtendibleLeaf::ExtendibleLeaf(int LSize)
{
  data = new int[LSize];
  LeafSize = LSize;
  count = 0;
}

ExtendibleLeaf * ExtendibleLeaf::insert(int object)
{
  if(count < LeafSize)
    {
      data[count] = object;
      count++;
      return NULL;
    }
  else
    {
      return split(object);
    }
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

ExtendibleLeaf * ExtendibleLeaf::split(int object) //pointer to new leaf
{
  //ExtendibleLeaf * newleaf = new ExtendibleLeaf(LeafSize);
  
}
