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
        strcpy(outFile, "Lenna_addcols.png");
    }

     if(strcmp(argv[1], "../images/duck.png") == 0) {
        strcpy(outFile, "duck_addcols.png");
    }

   uint32_t* img = LoadImage(argv[1], width, height);
   uint32_t x = 0xff000000;

    uint32_t* outCols = (uint32_t*)malloc(((w+(2*val)) * h) * sizeof(uint32_t));
        int j = 0;
        int im = 0;
        //uint32_t black;
         for (int i = 0; i < h; i++){
                  for(j = 0; j <= (val-1); j++){
                          outCols[ (w+2*val)*i + j] = x;
                  }
 
                  for(j = (val); j < w+val; j++){
                          outCols[(((w+(2*val))) * i) + j] = img[im];
                          im++;
                  }
                  for(j = (w + val ); j < ((w+(2*val))); j++){
                          outCols[(w+(2*val)) * i + j] = x;
                 }
         }


        SaveImage(outFile, outCols, (w+(2*val)), h); 

        free(img);  
        free(outCols);
    }

