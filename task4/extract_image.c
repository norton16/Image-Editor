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
    int startCol = atoi(argv[2]);
    int startRow = atoi(argv[3]);
    int newWidth = atoi(argv[4]);
    int newHeight = atoi(argv[5]);

    if(strcmp(argv[1], "../images/Lenna.png") == 0) {
        strcpy(outFile, "Lenna_extracted.png");
    }

     if(strcmp(argv[1], "../images/duck.png") == 0) {
        strcpy(outFile, "duck_extracted.png");
    }

   uint32_t* img = LoadImage(argv[1], width, height);
  
    uint32_t* outExt = (uint32_t*)malloc((newWidth * newHeight) * sizeof(uint32_t));
        int im = 0;
        //int new = 0;
        //uint32_t black;
        int n = ((w*startRow) + startCol);
         for (int i = 0; i < (newWidth * newHeight); i++){
             if(im == newWidth){
               
                n += (w-newWidth);
                 im = 0;
             }  
                  outExt[i] = img[n++];
                   //new++;
             im++;
         }


        SaveImage(outFile, outExt, newWidth, newHeight); 

        free(img);  
        free(outExt);
    }

