//////DO NOT MODIFY////////
#include "../lib/imageio.h"
//////DO NOT MODIFY////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

int main(int argc, char *argv[]) {
   int w = 0;
   int h = 0;
   int* width;
   width = &w;
   int* height;
   height = &h;

    char outFile[30];
    int val = atoi(argv[2]);
    

    if(strcmp(argv[1], "../images/Lenna.png") == 0) {
        strcpy(outFile, "Lenna_addrows.png");
    }

     if(strcmp(argv[1], "../images/duck.png") == 0) {
        strcpy(outFile, "duck_addrows.png");
    }

   uint32_t* img = LoadImage(argv[1], width, height);
   uint32_t x = 0xff000000;

    uint32_t* outRows = (uint32_t*)malloc((w * (h+(2*val))) * sizeof(uint32_t));
        int im = 0;
        int i = 0;

         for (i = 0; i < (w * val); i++){
           outRows[i] = x;
         }

         for (i = (w * val); i < (w * val)+(w * h); i++){
           outRows[i] = img[im];
           im++;
         }

        for (i = (w * val)+(w * h); i < (w * (h+(2*val))); i++){
            outRows[i] = x;
         }


        SaveImage(outFile, outRows, w, (h+(2*val))); 

        free(img);  
        free(outRows);
    }

