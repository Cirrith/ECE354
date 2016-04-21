/*
Ryan Bambrough, Section 1, Cheng-Hsiang Hsu, Section 1
*/

#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int main()
{
  
	//allocate enough space
	assert(Mem_Init(4096) == 0);
	
	//allocate memory
	void* ptr = Mem_Alloc(47);
  
	assert(ptr != NULL);
	
	//free allocated memory 
	assert(Mem_Free(ptr) == 0);
	
	//pass in the deallocated pointer ptr again as a bad pointer
	assert(Mem_Free(ptr) == -1);
	
	//pass in null to test bad pointer
	assert(Mem_Free(NULL) == -1);
	
	exit(0);
}