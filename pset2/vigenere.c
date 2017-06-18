#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

string cipher(string, string);
int isvalid(string);

int main(int argc, string argv[]){
    
    if(argc != 2 || !isvalid( argv[1] )){
        printf("INVALID STATEMENT\n");
        return 1;
    }
    
    
	string keyword = argv[1];
	
	for(int i = 0; keyword[i] != '\0'; i++){
	    keyword[i] = tolower(keyword[i]); //as case doesn't matter for key, all lower for simplicity
	}
	
	printf("plaintext:  ");
	string message = get_string();

	printf("ciphertext: %s\n", cipher(message, keyword) ); //printing the encrypted message
	return 0;
}

int isvalid(string keyword){
    
    for(int i = 0, n = strlen(keyword); i < n; i++){
        if(!isalpha( keyword[i] ))
            return 0; //either of non-alphabet characters will return FALSE
    }
    
    return 1; //if all alphabets
}

string cipher(string message, string key){
    
	int length = strlen(key);
    
	for(int i = 0, j = 0; message[i] != '\0'; i++){
	    if(j == length)
	        j = 0;
	        
	    if( isalpha(message[i]) ){
            
            if( isupper( message[i] ) ){
            	message[i] +=  isupper( key[j] ) ? key[j] - 'A' : key[j] - 'a'; //adding key
    			while(  message[i] > 'Z' ) //if exceeding ASCII, go round // for UPPER
    				message[i] -= 26;
            }
            
			else if( islower( message[i] ) ){
				message[i] +=  isupper( key[j] ) ? key[j] - 'A' : key[j] - 'a'; //adding key
        		while( !isalpha( message[i] )) //if exceeding ASCII, go round // for UPPER
    				message[i] -= 26;
			}
			
			j++;
		}
	}
	
	return message;
}