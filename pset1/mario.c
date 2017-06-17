#include <stdio.h>
#include <cs50.h>

int main(void){
    
    int height; //variable(s)
    
    do {
        printf("Height: ");
        height = get_int();
    }   while(height < 0 && height <= 23); //validation
    
    for(int i = 0; i < height; i++){
        
        for(int spaces = 0; spaces < height - 1 - i; spaces++)
            printf(" ");
            
        for(int asterik = 0; asterik < i + 2; asterik++)
            printf("#");
            
        printf("\n");
    }
}