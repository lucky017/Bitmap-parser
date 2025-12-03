
#include "../include/bm_common.h"

typedef struct tagBITMAPCOREHEADER  // bmch
{
     DWORD bcSize ;      // size of the structure = 12
     LONG  bcWidth ;     // width of image in pixels
     LONG  bcHeight ;    // height of image in pixels
     WORD  bcPlanes ;    // = 1
     WORD  bcBitCount ;  // bits per pixel (1, 4, 8, or 24)
}
BITMAPCOREHEADER, * PBITMAPCOREHEADER ;

static void init_core_header(PBITMAPCOREHEADER bm_core_header, FILE *bm_file)
{
    if(!bm_file) perror("BITMAP_CORE_HEADER");
    unsigned long rt;
    rt = fread(&bm_core_header->bcSize,    DWORD_SIZE,1, bm_file);
    rt = fread(&bm_core_header->bcWidth,   LONG_SIZE, 1, bm_file);
    rt = fread(&bm_core_header->bcHeight,  LONG_SIZE, 1, bm_file);
    rt = fread(&bm_core_header->bcPlanes,  WORD_SIZE, 1, bm_file);
    rt = fread(&bm_core_header->bcBitCount,WORD_SIZE, 1, bm_file); 
}



static void print_core_header(PBITMAPCOREHEADER bmch)
{
    if(!bmch) perror("BITMAP_CORE_HEADER");
    printf("BITMAP CORE HEADER SIZE : %d\
          \nBITMAP IMAGE WIDTH      : %d\
          \nBITMAP IMAGE HEIGHT     : %d\
          \nBITMAP CORE PLANES      : %d\
          \nBITMAP PIXEL BIT COUNT  : %d\n",
            bmch->bcSize, bmch->bcWidth, bmch->bcHeight, bmch->bcPlanes,bmch->bcBitCount );
}

