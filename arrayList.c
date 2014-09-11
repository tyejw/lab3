#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arrayList.h"

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

/*
 * The initialize method set up the fields for the array list and
 * allocates memory for the array. 
 * @param type - This is either an int, short, or char. It is needed
 * to determine how much memory to allocate. 
 */
arrayList * initialize(primitiveType type)
{
   int dynamic_size = 4 * getSize(type); 
   arrayList * array_mal = (arrayList*)(malloc(sizeof(arrayList)));
   array_mal->arraySize = 4;
   array_mal->elementSize = getSize(type);
   array_mal->numElements = 0;
   array_mal->type = type;
   array_mal->array = (void*)malloc(dynamic_size);
   return array_mal;    
   
}
/*
 * getSize will determine the size of the type.
 * @param type - the primitive type of the ArrayList.
 * @return - returns the size in bytes of the type.
 */
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
/*
 * Add's an element to the end of the array. If the number of elements
 * equals the size of the array the size of the array will be doubled.
 * @param aryLstP - pointer to the array list.
 * @param element - the element to be added to the array list.
 */
void addElement(arrayList * arylstP, void * element)
{
   if((arylstP->numElements) == (arylstP->arraySize))
   {
      
      int resize = (arylstP->numElements) * 2 * (arylstP->elementSize);
 	    void* resizedArray = (void*)malloc(resize);
      int n = (arylstP->numElements) * (arylstP->elementSize);    
	    memcpy(resizedArray, arylstP->array, n);
	    free(arylstP->array);
	    arylstP->array = resizedArray;
      arylstP->arraySize = arylstP->arraySize * 2;
   }    
    
   if(arylstP->type == intType)
   {
      int* pnt = (int*)arylstP->array;
	    int* elmnt = (int*)element;
	    pnt[arylstP->numElements] = *elmnt; 
   }	
   else if(arylstP->type == shortType)
   {
	    short* pnt = (short*)arylstP->array;
	    short* elmnt = (short*)element;
	    pnt[arylstP->numElements] = *elmnt; 
   }	
   else if(arylstP->type == charType)
   {
	    char* pnt = (char*)arylstP->array;
	    char* elmnt = (char*)element;
	    pnt[arylstP->numElements] = *elmnt; 
   }	
   (arylstP->numElements)++;
}

/*
 * Removes a element from the array at the specified index.
 * @param arylstP - pointer to the array list.
 * @param index - integer index to be removed.
 */
void removeElement(arrayList * arylstP, int index)
{
   int i;
   char size = (arylstP->numElements - 1);

   //int
   if ((arylstP->type) == intType)
   {
      for (i = index; i < size; i++)
      {
         int *pntpnt = (int*)arylstP->array;
         pntpnt[i] = pntpnt[i+1];	 
      }
   }
   //short
   if (arylstP->type == shortType)
   {
      for (i = index; i < size; i++)
      {
         short *pntpnt = (short*)arylstP->array;
         pntpnt[i] = pntpnt[i+1];
      }
   }
   if (arylstP->type == charType)
   {
      for (i = index; i < size; i++)
      {
         char *pntpnt = (char*)arylstP->array;
         pntpnt[i] = pntpnt[i+1];
      }
   }
   (arylstP->numElements)--;
} 

/*
 * Prints the array to output. 
 * @param arylstP - pointer to the array list. 
 */
void printArray(arrayList * arylstP)
{
   int i;
   printf("array size: %d, num elements: %d contents: ", 
          arylstP->arraySize, arylstP->numElements);
   for (i = 0; i < arylstP->numElements; i++)
   {
      if (arylstP->type == charType)
      {
         //fill in the missing code that gets the element and &s it with 0xff
         char *pntchar = (char*)arylstP->array;
         printf("%02x ", pntchar[i] & 0xff);
      }
      else if (arylstP->type == shortType)
      {
         //fill in the missing code that gets the element and &s it with 0xffff
         short *pntshort = (short*)arylstP->array;
         printf("%04x ", pntshort[i] & 0xffff);
      }
      else if (arylstP->type == intType)
      {
         //fill in the missing code that gets the element and &s it with 0xffffffff
         int *pntint = (int*)arylstP->array;
         printf("%08x ", pntint[i] & 0xffffffff);
      }
   }
   printf("\n");
}
