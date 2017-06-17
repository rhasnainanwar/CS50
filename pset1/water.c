#include <stdio.h>
#include <cs50.h>

int main(void){
    
    int minutes, bottles; //variables
    
    printf("Minutes: ");
    minutes = get_int(); //input
    
    bottles = minutes * 12; //calculation
    
    printf("Minutes: %i\n", bottles);
}