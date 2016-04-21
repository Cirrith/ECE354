
#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int main()
{
	
	//allocate enough space
	assert(Mem_Init(4096) == 0);
	
	//allocate memory
	void* pointer; = Mem_Alloc(47);
	assert(pointer != NULL);
	
	//free allocated memory 
	assert(Mem_Free(pointer) == 0);
	
	//pass in the deallocated pointer ptr again as a bad pointer
	assert(Mem_Free(pointer) == -1);
	
	//pass in null to test bad pointer
	asser(Mem_Free(NULL) == -1);
	
	exit(0);
}