

#ifndef BM_FILE_HEADER_H
#define BM_FILE_HEADER_H

#include "bm_common.h"

#pragma pack(push, 1)
typedef struct tagBITMAPFILEHEADER  // bmfh
{ 
     WORD  bfType ;        // signature word "BM" or 0x4D42
     DWORD bfSize ;        // entire size of file
     WORD  bfReserved1 ;   // must be zero
     WORD  bfReserved2 ;   // must be zero
     DWORD bfOffsetBits ;  // offset in file of DIB pixel bits
}
BITMAPFILEHEADER, * PBITMAPFILEHEADER ;
#pragma pack(pop)


void init_file_header(PBITMAPFILEHEADER bmfh, DWORD bmp_size, DWORD bmp_offbits);
void read_bmfh_from_file(PBITMAPFILEHEADER bmfh,  FILE *bmp_file);
void print_file_header(PBITMAPFILEHEADER bmfh);



#endif
