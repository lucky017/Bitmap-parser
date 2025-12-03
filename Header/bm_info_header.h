
#ifndef BM_INFO_HEADER_H
#define BM_INFO_HEADER_H

#include "../include/bm_common.h"

#pragma pack(push, 1)
typedef struct tagBITMAPINFOHEADER  // bmih
{
     DWORD biSize ;           // size of the structure = 40
     LONG  biWidth ;          // width of the image in pixels
     LONG  biHeight ;         // height of the image in pixels
     WORD  biPlanes ;         // = 1
     WORD  biBitCount ;       // bits per pixel (1, 4, 8, 16, 24, or 32)
     DWORD biCompression ;    // compression code
     DWORD biSizeImage ;      // number of bytes in image
     LONG  biXPelsPerMeter ;  // horizontal resolution
     LONG  biYPelsPerMeter ;  // vertical resolution
     DWORD biClrUsed ;        // number of colors used
     DWORD biClrImportant ;   // number of important colors
}
BITMAPINFOHEADER, * PBITMAPINFOHEADER ;

static void init_info_header(PBITMAPINFOHEADER bm_info_header, FILE *bm_file)
{
    if(!bm_file) perror("BITMAP_INFO_HEADER");
    fread(&bm_info_header->biSize,          DWORD_SIZE, 1, bm_file);
    fread(&bm_info_header->biWidth,         LONG_SIZE,  1, bm_file);
    fread(&bm_info_header->biHeight,        LONG_SIZE,  1, bm_file);
    fread(&bm_info_header->biPlanes,        WORD_SIZE,  1, bm_file);
    fread(&bm_info_header->biBitCount,      WORD_SIZE,  1, bm_file); 
    fread(&bm_info_header->biCompression,   DWORD_SIZE, 1, bm_file);
    fread(&bm_info_header->biSizeImage,     DWORD_SIZE, 1, bm_file);
    fread(&bm_info_header->biXPelsPerMeter, LONG_SIZE,  1, bm_file);
    fread(&bm_info_header->biYPelsPerMeter, LONG_SIZE,  1, bm_file);
    fread(&bm_info_header->biClrUsed,       DWORD_SIZE, 1, bm_file);
    fread(&bm_info_header->biClrImportant,  DWORD_SIZE, 1, bm_file);
}


static void print_info_header(PBITMAPINFOHEADER info)
{
    if(!info) perror("BITMAP_INFO_HEADER");
    printf("BITMAP INFO HEADER SIZE : %d\
                  \nBITMAP IMAGE WIDTH      : %d\
                  \nBITMAP IMAGE HEIGHT     : %d\
                  \nBITMAP CORE PLANES      : %d\
                  \nBITMAP PIXEL BIT COUNT  : %d\
                  \nBITMAP COMPRESSION CODE : %d\
                  \nBITMAP IMAGE SIZE       : %d\
                  \nHORIZONTAL RESOLUTION   : %d\
                  \nVERTICAL RESOLUTION     : %d\
                  \nBITMAP COLORS USED      : %d\
                  \nBITMAP IMPORTANT COLORS : %d\n",
          info->biSize, info->biWidth, info->biHeight, info->biPlanes, info->biBitCount,
          info->biCompression, info->biSizeImage, info->biXPelsPerMeter, info->biYPelsPerMeter,
          info->biClrUsed, info->biClrImportant 
          );
}

#pragma pack(pop)

#endif
