

#include "../../include/bm_info_header.h"



void init_info_header(PBITMAPINFOHEADER bmih, LONG width, LONG height, DWORD bm_imagesize)
{
    if(!bmih){
        fputs("INFO HEADER IS NOT. CAN'T CONSTRUCT OBJECT\n", stderr);
        return;
    }
    const int bmih_size = sizeof(BITMAPINFOHEADER);
    bmih->biSize = bmih_size;
    bmih->biWidth = width;
    bmih->biHeight = height;
    bmih->biPlanes = 1;
    bmih->biBitCount = 24;  //                                           Alternative options would be 16, 32 and 64
    bmih->biCompression = 0;
    bmih->biSizeImage = bm_imagesize;
    bmih->biXPelsPerMeter = bmih->biYPelsPerMeter = 0;
    bmih->biClrUsed = bmih->biClrImportant = 0; 
}

void write_bmih_from_file(PBITMAPINFOHEADER bmih, FILE *bm_file)
{
    if(!bmih && !bm_file) {
        fputs("[[ ERROR ]] :: INFO HEADER :: CAN'T READ CONTENTS\n", stdout);
        return;
    } 
    char c;
    scanf("re-writing the contents in info header\ndo you wish to proceed[y/n] : %c",&c);
    if(c == 'n' || c == 'N') return;
    else if(c != 'y' || c != 'Y'){
        fputs("[ERROR] : wrong option!! Try Again...\n", stderr);
        return;
    }

    fread(&bmih->biSize,          DWORD_SIZE, 1, bm_file);
    fread(&bmih->biWidth,         LONG_SIZE,  1, bm_file);
    fread(&bmih->biHeight,        LONG_SIZE,  1, bm_file);
    fread(&bmih->biPlanes,        WORD_SIZE,  1, bm_file);
    fread(&bmih->biBitCount,      WORD_SIZE,  1, bm_file); 
    fread(&bmih->biCompression,   DWORD_SIZE, 1, bm_file);
    fread(&bmih->biSizeImage,     DWORD_SIZE, 1, bm_file);
    fread(&bmih->biXPelsPerMeter, LONG_SIZE,  1, bm_file);
    fread(&bmih->biYPelsPerMeter, LONG_SIZE,  1, bm_file);
    fread(&bmih->biClrUsed,       DWORD_SIZE, 1, bm_file);
    fread(&bmih->biClrImportant,  DWORD_SIZE, 1, bm_file);

}


void print_info_header(PBITMAPINFOHEADER info)
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


