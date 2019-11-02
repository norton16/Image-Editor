//////DO NOT MODIFY////////
#include "../lib/imageio.h"
//////DO NOT MODIFY////////
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
   int w = 0;
   int h = 0;
   int* width;
   width = &w;
   int* height;
   height = &h;

    char input[30];
    char outFile[30];
    strcpy(input, argv[1]);

    if(strcmp(input, "../images/Lenna.png") == 0) {
        strcpy(outFile, "Lenna_negate.png");
    }

     if(strcmp(input, "../images/duck.png") == 0) {
        strcpy(outFile, "duck_negate.png");
    }

   uint32_t* img = LoadImage(argv[1], width, height);
          
    uint32_t* outNeg = (uint32_t*)malloc((w * h) * sizeof(uint32_t));
       
       
        for (int i = 0; i < (w*h); i++) {    
            outNeg[i] = (img[i] ^ 0x00ffffff);
        }

        SaveImage(outFile, outNeg, w, h); 

        free(img);  
        free(outNeg);
    }

