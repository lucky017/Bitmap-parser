
#ifndef BM_INFO_HEADER_H
#define BM_INFO_HEADER_H

#include "bm_common.h"

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
#pragma pack(pop)

void init_info_header(PBITMAPINFOHEADER bmih, LONG width, LONG height, DWORD bm_imagesize);
void write_bmih_from_file(PBITMAPINFOHEADER bmih, FILE *bm_file);
void print_info_header(PBITMAPINFOHEADER info);


#endif
