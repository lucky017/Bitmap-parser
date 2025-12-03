
#include "include/Bitmap.h"

int main(void)
{
    struct bitmap bmp = init_bitmap(200, 200);
    fill(&bmp, 0, 0, 200, 200, 0xFFFFFF); 
    write_bitmap(&bmp, "out.bmp");
    free_bitmap(&bmp);
    return 0;

}
