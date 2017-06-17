#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void){
    
    string name = get_string();
    char initials[5];
    int j = 0;
    
    //pre-check
    // if the following line were to be put inside the loop,
    // it would have increased number of IF's inside the loop %/
    
    if(name[0] != ' ')
        initials[j++] = toupper(name[0]);
        
    for(int i = 1, length = strlen(name); i < length; i++){
        
        if( name[i] != ' ' && name[i - 1] == ' ') //a way to be not tricked by spaces
            initials[j++] = toupper(name[i]);
    }
    
    printf("%s\n", initials);
}