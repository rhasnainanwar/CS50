#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

int main(int argc, char *argv[]){
    
    if(argc != 2){
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    //input file pointer
    FILE* inptr = fopen(argv[1], "r");
    
    if(inptr == NULL){
        fprintf(stderr, "Can't open %s \n", argv[1]);
        return 2;
    }
    
    //counting number of image found and read
    int count = 0;
    //opening a file to write
    int size = 512; //size of buffer
    
    //other variables
    FILE* img = NULL;
    uint8_t buffer[512];
    
    //validation variable(s)
    bool start = false; //shows that images have started
    
    
    while( fread(buffer, size, 1, inptr) > 0){ //until EOF
        if(buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            ((buffer[3] & 0xf0) == 0xe0)){ //jpeg signature
                if(img != NULL){ //if a file already opened, 
                    fclose(img); //close it
                }
                char filename[8]; 
                sprintf(filename, "%03d.jpg", count++);
                img = fopen(filename, "w"); //and open a new one
                start = true;
        }
        if(start) //if the jpeg sequence has started
            fwrite(buffer, size, 1, img);
    }
    fclose(img); //close the last one
    
    return 0;
}