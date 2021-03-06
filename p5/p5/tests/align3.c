/* many odd sized allocations checked for alignment */
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include "mem.h"

int main() {
   assert(Mem_Init(4096) == 0);
   int* ptr[9];
   ptr[0] = Mem_Alloc(1);
   Mem_Dump();
   ptr[1] = (Mem_Alloc(5));
   Mem_Dump();
   ptr[2] = (Mem_Alloc(14));
   Mem_Dump();
   ptr[3] = (Mem_Alloc(8));
   Mem_Dump();
   ptr[4] = (Mem_Alloc(1));
   Mem_Dump();
   ptr[5] = (Mem_Alloc(4));
   Mem_Dump();
   ptr[6] = (Mem_Alloc(9));
   Mem_Dump();
   ptr[7] = (Mem_Alloc(33));
   Mem_Dump();
   ptr[8] = (Mem_Alloc(55));
   Mem_Dump();

   assert((int)(ptr[0]) % 4 == 0);
   assert((int)(ptr[1]) % 4 == 0);
   assert((int)(ptr[2]) % 4 == 0);
   assert((int)(ptr[3]) % 4 == 0);
   assert((int)(ptr[4]) % 4 == 0);
   assert((int)(ptr[5]) % 4 == 0);
   assert((int)(ptr[6]) % 4 == 0);
   assert((int)(ptr[7]) % 4 == 0);
   assert((int)(ptr[8]) % 4 == 0);

   exit(0);
}
