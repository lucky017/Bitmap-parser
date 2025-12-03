

#ifndef BM_FILE_HEADER_H
#define BM_FILE_HEADER_H

#include "../include/bm_common.h"

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

static void init_header(PBITMAPFILEHEADER bmp_header, FILE *bmp_file)
{
    if(!bmp_file) perror("BITMAPFILE");
    unsigned long rt = 0;
    rt = fread(&bmp_header->bfType, WORD_SIZE, 1, bmp_file);
    rt = fread(&bmp_header->bfSize, DWORD_SIZE, 1, bmp_file);
    rt = fread(&bmp_header->bfReserved1, WORD_SIZE, 1, bmp_file);
    rt = fread(&bmp_header->bfReserved2, WORD_SIZE, 1, bmp_file);
    rt = fread(&bmp_header->bfOffsetBits, DWORD_SIZE, 1, bmp_file); 
}

static void print_header(PBITMAPFILEHEADER bmp_header)
{
    char *ptr = (char*)&bmp_header->bfType;
    char type[2] = { *ptr, *(ptr+1) };
    printf("FILE TYPE : %s\
                  \nFILE SIZE : %u\
                  \nFILE OFFSET SIZE : %u\n", 
                    type, bmp_header->bfSize, bmp_header->bfOffsetBits);
}

#pragma pack(pop)
#endif
