
#include "../include/Bitmap.h"
#include "../Header/bm_file_header.h"
#include "../Header/bm_info_header.h"
#include<stdlib.h>

struct bitmap init_bitmap(int width, int height)
{
    color_t* pixels = (color_t*) malloc(width * height * sizeof(color_t));

    struct bitmap bmp = { .width=width, .height=height, .pixels=pixels };
    return bmp;
}

void set_pixel(struct bitmap *bmp, int x, int y, color_t color)
{
    if(x < 0 || x >= bmp->width || y < 0 || y >= bmp->height) return;
    bmp->pixels[y * bmp->width + x] = color;
}


int row_length(int width)
{
    int row_length = 3 * width;
    row_length += 4 - (row_length % 4);
    return row_length;
}
int image_size(int width, int height) {
    return row_length(width) * height;
}

void write_file_header(struct bitmap* bmp, FILE* bmp_file) 
{
    unsigned int off_size = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER),
                 filesize = off_size + image_size(bmp->width, bmp->height);
    BITMAPFILEHEADER bmfh = { 0x4d42, filesize, 0, 0, off_size };
    fwrite(&bmfh, sizeof(bmfh), 1, bmp_file);
    //print_header(&bmfh); 
}

void write_info_header(struct bitmap* bmp, FILE* bmp_file)
{
    unsigned int filesize = image_size(bmp->width, bmp->height);
    BITMAPINFOHEADER bmih = { sizeof(BITMAPINFOHEADER), bmp->width, bmp->height, 1, 3*8*sizeof(u_int8_t), 0, 
                              filesize, 0, 0, 0, 0};
    fwrite(&bmih, sizeof(BITMAPINFOHEADER), 1, bmp_file);
    //print_info_header(&bmih);
}

void write_pixel_data(struct bitmap* bmp, FILE* bmp_file)
{
    int count = 0;
    for(int y=bmp->height-1; y >= 0; --y){
        for(int x=0; x < bmp->width; ++x){
            color_t color = bmp->pixels[y * bmp->width + x];
            unsigned char green = (color & 0x00FF00) >> 8;
            unsigned char blue = color & 0x0000FF;
            //            printf("COLOR[%d, %d] = %du  { ", x, y, color);
            //            printf("red = %d, green = %d, blue = %d }\n", (int)red, (int)green, (int)blue);
            unsigned char red = (color & 0xFF0000) >> 16;
            fwrite(&blue, 1, 1, bmp_file);
            fwrite(&green, 1, 1, bmp_file);
            fwrite(&red, 1, 1, bmp_file);
            ++count;
        }
    }
        //    printf("WRITE COUNT BUFFER = %d\n", count);
}

void fill(struct bitmap *bmp, int x1, int y1, int x2, int y2, color_t color)
{
    int a = 0;
    for(int y = y1; y <= y2; ++y){
        for(int x = x1; x <= x2; ++x){
        //            printf("COLOR[%d, %d] = %du\n", x, y, color); 
            set_pixel(bmp, x, y, color);
            ++a;
        }
    }
    //    printf("COUNT = %d\n\n", a);
}

int write_bitmap(struct bitmap* bmp, const char* filename)
{
    FILE *bmp_file = fopen(filename, "wb");
    if(bmp_file == NULL) return 1;
    write_file_header(bmp, bmp_file);
    write_info_header(bmp, bmp_file);
    write_pixel_data(bmp, bmp_file);
    fclose(bmp_file);
    return 0;
}

void free_bitmap(struct bitmap* bmp)
{
    free(bmp->pixels);
    bmp->pixels = NULL;
}

