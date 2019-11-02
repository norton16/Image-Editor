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
    char redFile[30];
    char greenFile[30];
    char blueFile[30];
    strcpy(input, argv[1]);

    if(strcmp(input, "../images/Lenna.png") == 0) {
        strcpy(redFile, "Lenna_red.png");
        strcpy(greenFile, "Lenna_green.png");
        strcpy(blueFile, "Lenna_blue.png");
    }

// printf("%s", greenFile);

     if(strcmp(input, "../images/duck.png") == 0) {
        strcpy(redFile, "duck_red.png");
        strcpy(greenFile, "duck_green.png");
        strcpy(blueFile, "duck_blue.png");
    }

   uint32_t* img = LoadImage(argv[1], width, height);
   //img = (uint32_t*)malloc((w * h) * sizeof(uint32_t)); 
               
        //unsigned char* pixel = (unsigned char*)malloc(4 * sizeof(unsigned char));
        uint32_t* outRed = (uint32_t*)malloc((w * h) * sizeof(uint32_t));
        uint32_t* outBlue = (uint32_t*)malloc((w * h) * sizeof(uint32_t));
        uint32_t* outGreen = (uint32_t*)malloc((w * h) * sizeof(uint32_t));
       
        //RED
        for (int i = 0; i < (w*h); i++) { 
            
            // pixel[0] = (img[i] >> 24) ; //alpha
            // pixel[1] = (img[i] >> 16) & 0xff; //blue
            // pixel[2] = (img[i] >> 8) & 0xff; //green
            // pixel[3] = img[i] & 0xff; //red

            outRed[i] = img[i] & 0xff0000ff;
            outBlue[i] = img[i] & 0xffff0000;
            outGreen[i] = img[i] & 0xff00ff00;

            // outRed[1] = img[i] >> 8 & 0xff00ff00;
            // outRed[2] = img[i] >> 16 & 0xffff0000;
            // outRed[3] = img[i] >> 24 & 0xff000000;

            // r = (pixel[0] << 24) | 
            // (pixel[1] << 16) | 
            // (pixel[2] << 8) | 
            // (pixel[3]);
        }

        SaveImage(redFile, outRed, w, h); 
        SaveImage(blueFile, outBlue, w, h); 
        SaveImage(greenFile, outGreen, w, h); 
        
        free(img);  
        free(outRed);
        free(outBlue);
        free(outGreen);
    }

