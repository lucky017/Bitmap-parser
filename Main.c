
#include "include/Bitmap.h"

int main(void)
{
    const int width  = 1080, 
              height = 720;
    struct bitmap bmp = init_bitmap(width, height);
    fill(&bmp, 0, 0, width, height, 0x00a01f); 
    write_bitmap(&bmp, "output.bmp");
    free_bitmap(&bmp);
    return 0;

}
