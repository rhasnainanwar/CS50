#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    
    float owed;//variable
    
    do {
        printf("How much is owed?\n");
        owed = get_float();
    } while(owed < 0);//validation
    
    owed *= 100;//converting to cents
    owed = ceil(owed);
    
    int coins = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    
    if(owed >= quarter){
        coins += (int)owed/quarter;
        owed = ((int)owed % quarter);
    }
    if(owed >= dime){
        coins += (int)owed/dime;
        owed = ((int)owed % dime);
    }
    if(owed >= nickel){
        coins += (int)owed/nickel;
        owed = ((int)owed % nickel);
    }
    if(owed >= penny){
        coins += (int)owed;
    }
    
    printf("%i\n", coins);
}