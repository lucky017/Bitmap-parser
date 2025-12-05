
#include "../include/Bitmap.h"

int row_length(int width)
{
    int row_length = 3 * width;
    row_length += 4 - (row_length % 4);
    return row_length;
}
int image_size(int width, int height) {
    return row_length(width) * height;
}


/**
 *      STARTS HERE 
 */

void init_bitmap(struct bitmap *bmp, int width, int height)
{
    bmp->width = width;
    bmp->height = height;
    bmp->pixels = (color_t*) malloc(width * height * sizeof(color_t));
    const unsigned int  bmfh_size = sizeof(BITMAPFILEHEADER), bmih_size = sizeof(BITMAPINFOHEADER),
                        offset_size = bmfh_size + bmih_size,
                        bm_imagesize = image_size(width, height),
                        bm_filesize  = offset_size + bm_imagesize;
    
    init_file_header(&bmp->bm_file_header, bm_filesize, offset_size); 
    init_info_header(&bmp->bm_info_header, width, height, bm_imagesize);        
}

void set_pixel(struct bitmap *bmp, int x, int y, color_t color)
{
    if(x < 0 || x >= bmp->width || y < 0 || y >= bmp->height) return;
    bmp->pixels[y * bmp->width + x] = color;
}


void write_pixel_data(struct bitmap* bmp, FILE* bmp_file)
{
            //      int count = 0;
    printf("WIDTH = %d\nHEIGHT = %d\n", bmp->width, bmp->height);
    for(int y=bmp->height-1; y >= 0; --y){
        for(int x=0; x < bmp->width; ++x){
            color_t color = bmp->pixels[y * bmp->width + x];
            unsigned char red = (color & 0xFF0000) >> 16;
            unsigned char green = (color & 0x00FF00) >> 8;
            unsigned char blue = color & 0x0000FF;
            //                                              printf("COLOR[%d, %d] = %du  { ", x, y, color);
            //                                              printf("red = %d, green = %d, blue = %d }\n", (int)red, (int)green, (int)blue);
            fwrite(&blue, 1, 1, bmp_file);
            fwrite(&green, 1, 1, bmp_file);
            fwrite(&red, 1, 1, bmp_file);
            // ++count;
        }
    }
            //                                           printf("WRITE COUNT BUFFER = %d\n", count);
}

void fill(struct bitmap *bmp, int x1, int y1, int x2, int y2, color_t color)
{
    int a = 0;
    for(int y = y1; y <= y2; ++y){
        for(int x = x1; x <= x2; ++x){
            //                                              printf("COLOR[%d, %d] = %du\n", x, y, color); 
            set_pixel(bmp, x, y, color);
            ++a;
        }
    }
            //                                              printf("COUNT = %d\n\n", a);
}

void write_file_header(struct bitmap *bmp, FILE *bmp_file)
{
    if(!bmp) perror("WRITING BITMAP FILE HEADER FAILED!!");
    fwrite(&bmp->bm_file_header, sizeof(BITMAPFILEHEADER), 1, bmp_file);
}

void write_info_header(struct bitmap *bmp, FILE *bmp_file)
{
    if(!bmp) perror("WRITING BITMAP INFO HEADER FAILED!!");
    fwrite(&bmp->bm_info_header, sizeof(BITMAPINFOHEADER), 1, bmp_file);
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

void bm_parse_bitmap_pixels(struct bitmap *bmp, FILE *bmp_file)
{
    if(!bmp_file || !bmp) perror("BITMAP");
//    fread(bmp->pixels, image_size, 1);

}

void free_bitmap(struct bitmap* bmp)
{
    if(bmp->pixels) free(bmp->pixels);
    bmp->pixels = NULL;
}

