/* many odd sized allocations and interspersed frees */
#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int main() {
   assert(Mem_Init(4096) == 0);
   void * ptr[9];
   ptr[0] = Mem_Alloc(1);
   Mem_Dump();
   ptr[1] = (Mem_Alloc(5));
   Mem_Dump();
   ptr[2] = (Mem_Alloc(14));
   Mem_Dump();
   ptr[3] = (Mem_Alloc(8));
   Mem_Dump();
   assert(ptr[0] != NULL);
   assert(ptr[1] != NULL);
   assert(ptr[2] != NULL);
   assert(ptr[3] != NULL);

   assert(Mem_Free(ptr[1]) == 0);
   Mem_Dump();
   assert(Mem_Free(ptr[0]) == 0);
   Mem_Dump();
   assert(Mem_Free(ptr[3]) == 0);
   Mem_Dump();

   ptr[4] = (Mem_Alloc(1));
   Mem_Dump();
   ptr[5] = (Mem_Alloc(4));
   Mem_Dump();

   assert(ptr[4] != NULL);
   assert(ptr[5] != NULL);

   assert(Mem_Free(ptr[5]) == 0);
   Mem_Dump();

   ptr[6] = (Mem_Alloc(9));
   Mem_Dump();
   ptr[7] = (Mem_Alloc(33));
   Mem_Dump();
   assert(ptr[6] != NULL);
   assert(ptr[7] != NULL);

   assert(Mem_Free(ptr[4]) == 0);
   Mem_Dump();

   ptr[8] = (Mem_Alloc(55));
   Mem_Dump();
   assert(ptr[8] != NULL);

   assert(Mem_Free(ptr[2]) == 0);
   Mem_Dump();
   assert(Mem_Free(ptr[7]) == 0);
   Mem_Dump();
   assert(Mem_Free(ptr[8]) == 0);
   Mem_Dump();
   assert(Mem_Free(ptr[6]) == 0);
   Mem_Dump();

   exit(0);
}
