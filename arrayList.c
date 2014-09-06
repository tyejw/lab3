#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

arrayList * initialize(primitiveType type)
{
   int dynamic_size = 4 * getSize(type); 
   arrayList * array_mal = (arrayList*)(malloc(sizeof(arrayList)));
   array_mal->arraySize = 4;
   array_mal->elementSize = getSize(type);
   array_mal->numElements = 0;
   array_mal->type = type;
   array_mal->array = malloc(dynamic_size);
   return array_mal;    
   
}

int getSize(primitiveType type)
{
   if(type == charType)
   {
       return sizeof(char);
   }
   if (type == shortType)
   {
       return sizeof(short);
   }
   return sizeof(int);

}

void addElement(arrayList * arylstP, void * element)
{
   return;
}

void removeElement(arrayList * arylstP, int index)
{
   char c;

   char size = (arylstP->numElements - 1) * (arylstP->elementSize);

   char *pntpnt;

   pntpnt = arylstP->array;

   for(c = index; c < size; c++)
    {
        pntpnt[c] = pntpnt[c+1];
    }
}
      

void printArray(arrayList * arylstP)
{
   int i;
   printf("array size: %d, num elements: %d contents: ", 
          arylstP->arraySize, arylstP->numElements);
   for (i = 0; i < arylstP->numElements; i++)
   {
      if (arylstP->type == charType)
         //fill in the missing code that gets the element and &s it with 0xff
         printf("%02x ", 0xff);
      else if (arylstP->type == shortType)
         //fill in the missing code that gets the element and &s it with 0xffff
         printf("%04x ", 0xffff);
      else if (arylstP->type == intType)
         //fill in the missing code that gets the element and &s it with 0xffffffff
         printf("%08x ", 0xffffffff);
   }
   printf("\n");
}

