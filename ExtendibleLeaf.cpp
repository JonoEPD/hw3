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
      if(data[i] == object) //found
	{
	  removeDriver(i);
	  i = count + 1; //break out
	}
    }
  //note: if empty, just leave it be (no merge)
}

void ExtendibleLeaf::removeDriver(int index)
{
  for(int i = index; i < count-1; i++) //shift down
    {
      data[i] = data[i+1];
    }
  data[count-1] = 0;
  --count;
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
  for(int i = 0; i < count; i++)
    {
      if(EHash(data[i],bits) != mark) //found a value to split
	{
	  int newmark = EHash(data[i],bits);
	  dir[newmark] = new ExtendibleLeaf(LeafSize);
	  dir[newmark]->insertDriver(data[i]); //put it in
	  removeDriver(i); //take it out

	  for(int j = i; j < count; j++) //shifted, so [j] = [i+1]
	    {
	      if(EHash(data[j],bits) == newmark)
		{
		  dir[newmark]->insertDriver(data[j]); //put it in
		  removeDriver(j); //take it out
		  j--; //we shifted
		}
	    }
	  insertDriver(object);
	  return NULL; //break out
	}
    }
  return 1; //failed to split
}



