
#include "include/Bitmap.h"

int main(void)
{
    const int width  = 1080, 
              height = 720;
    struct bitmap bmp; 
    init_bitmap(&bmp, width, height);
    
    fill(&bmp, 0, 0         , width, height/3,      0xFF0000);
    fill(&bmp, 0, height/3  , width, 2 * height/3,  0x002025);
    fill(&bmp, 0, 2*height/3, width, height,        0x001020);
     
    
    write_bitmap(&bmp, "output.bmp");
    free_bitmap(&bmp);
    
    return 0;

}
