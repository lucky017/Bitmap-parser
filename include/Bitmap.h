
#include "stdio.h"
#include<stdlib.h>
typedef unsigned int color_t;

struct bitmap
{
    int width;
    int height;
    color_t *pixels;
};

struct bitmap init_bitmap(int width, int height);

void set_pixel(struct bitmap *bmp, int x, int y, color_t color);
void free_bitmap(struct bitmap* bmp);

void fill(struct bitmap *bmp, int x1, int y1, int x2, int y2, color_t color);

int write_bitmap(struct bitmap *bmp, const char* filename);
void write_file_header(struct bitmap *bmp, FILE *bmp_file);
void write_info_header(struct bitmap *bmp, FILE *bmp_file);
void write_pixel_data(struct bitmap *bmp, FILE *bmp_file);

