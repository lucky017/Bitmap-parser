


#include "../../include/bm_file_header.h"


void init_file_header(PBITMAPFILEHEADER bmfh, DWORD bmp_size, DWORD bmp_offbits){
    if(!bmfh){ 
        fputs("FILE HEADER IS NULL. CAN'T CONSTRUCT OBJECT", stderr);
        return; 
    }
    bmfh->bfType = 0x4d42;
    bmfh->bfSize = bmp_size;
    bmfh->bfReserved1 = bmfh->bfReserved2 = 0;
    bmfh->bfOffsetBits = bmp_offbits;
}


void read_bmfh_from_file(PBITMAPFILEHEADER bmfh,  FILE *bmp_file)
{ 
    if(!bmfh || !bmp_file){
        fputs("[[ ERROR ]] :: FILE HEADER :: CAN'T READ CONTENTS\n", stderr);
        return; 
    }
    char c;
    scanf("re-writing the contents in file header\ndo you wish to proceed[y/n] : %c",&c);
    if(c == 'n' || c == 'N') return;
    else if(c != 'y' || c != 'Y'){
        fputs("[ERROR] : wrong option!! Try Again...\n", stderr);
        return;
    }
    fread(&bmfh->bfType,      WORD_SIZE,   1, bmp_file);
    fread(&bmfh->bfSize,      DWORD_SIZE,  1, bmp_file);
    fread(&bmfh->bfReserved1, WORD_SIZE,   1, bmp_file);
    fread(&bmfh->bfReserved2, WORD_SIZE,   1, bmp_file);
    fread(&bmfh->bfOffsetBits,DWORD_SIZE,  1, bmp_file);    
}


void print_file_header(PBITMAPFILEHEADER bmfh)
{
    char *ptr = (char*)&bmfh->bfType;
    char bm_type[2] = { *ptr, *(ptr+1) };
    printf("FILE TYPE : %s\
                  \nFILE SIZE : %u\
                  \nBITMAP RESERVED 1 : %u\
                  \nBITMAP RESERVED 2 : %u\
                  \nFILE OFFSET SIZE : %u\n", 
                    bm_type, bmfh->bfSize, bmfh->bfReserved1, 
                    bmfh->bfReserved2,  bmfh->bfOffsetBits);
}

