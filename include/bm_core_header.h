
#ifndef BM_CORE_HEADER_H
#define BM_CORE_HEADER_H

#include "bm_common.h"

#pragma pack(push, 1)
typedef struct tagBITMAPCOREHEADER  // bmch
{
     DWORD bcSize ;      // size of the structure = 12
     LONG  bcWidth ;     // width of image in pixels
     LONG  bcHeight ;    // height of image in pixels
     WORD  bcPlanes ;    // = 1
     WORD  bcBitCount ;  // bits per pixel (1, 4, 8, or 24)
}
BITMAPCOREHEADER, * PBITMAPCOREHEADER ;
#pragma pack(pop)


void init_core_header(PBITMAPCOREHEADER bm_core_header, FILE *bm_file);
void print_core_header(PBITMAPCOREHEADER bmch);

#endif
