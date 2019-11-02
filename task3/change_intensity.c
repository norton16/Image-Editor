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
    float v = (float)val;
    

    if(strcmp(argv[1], "../images/Lenna.png") == 0) {
        strcpy(outFile, "Lenna_intensity.png");
    }

     if(strcmp(argv[1], "../images/duck.png") == 0) {
        strcpy(outFile, "duck_intensity.png");
    }

   uint32_t* img = LoadImage(argv[1], width, height);

   float a;
   float b;
   float g;
   float r;

    uint32_t* outIntensity = (uint32_t*)malloc((w * h) * sizeof(uint32_t));
       
        for (int i = 0; i < (w*h); i++) {
            if(val > 0){
             a = (float)(img[i] >> 24);
             b = (1+(v*.01))*((float)(img[i] >> 16 & 0xff)); //blue
             g = (1+(v*.01))*((float)(img[i] >> 8 & 0xff)); //green
             r = (1+(v*.01))*((float)(img[i] & 0xff)); //red
            }
            if(val < 0){
             a = (float)(img[i] >> 24 & 0xff000000);
             b = (0+(v*.01))*((float)(img[i] >> 16 & 0xff)); //blue
             g = (0+(v*.01))*((float)(img[i] >> 8 & 0xff)); //green
             r = (0+(v*.01))*((float)(img[i] & 0xff)); //red
            }

            int aa = trunc(a);
            int bb = trunc(b);
            int gg = trunc(g);
            int rr = trunc(r);

            if(bb < 0){
                bb = 0;
            }
             if(gg < 0){
                gg = 0;
            }
             if(rr < 0){
                rr = 0;
            }

            if(bb > 255){
                bb = 255;
            }
             if(gg > 255){
                gg = 255;
            }
             if(rr > 255){
                rr = 255;
            }

            outIntensity[i] = (aa << 24) | 
             (bb << 16) | 
             (gg << 8) | 
             (rr);
        }

        SaveImage(outFile, outIntensity, w, h); 

        free(img);  
        free(outIntensity);
    }

