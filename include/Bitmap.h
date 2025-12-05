
#include "bm_common.h"
#include "bm_file_header.h"
#include "bm_core_header.h"
#include "bm_info_header.h"

typedef unsigned int color_t;

struct bitmap
{
    int width;
    int height;
    BITMAPFILEHEADER bm_file_header;
    BITMAPINFOHEADER bm_info_header;
    color_t *pixels;
};

// Use BITMAP CORE HEADER if you're using backward campatible bitmap files...
void init_bitmap(struct bitmap *bmp, int width, int height);

void set_pixel(struct bitmap *bmp, int x, int y, color_t color);
void free_bitmap(struct bitmap* bmp);


int write_bitmap(struct bitmap *bmp, const char* filename);
void write_file_header(struct bitmap *bmp, FILE *bmp_file);
void write_info_header(struct bitmap *bmp, FILE *bmp_file);
void write_pixel_data(struct bitmap *bmp, FILE *bmp_file);

void fill(struct bitmap *bmp, int x1, int y1, int x2, int y2, color_t color);
void bm_parse_bitmap_pixels(struct bitmap *bmp, FILE *bmp_file);
