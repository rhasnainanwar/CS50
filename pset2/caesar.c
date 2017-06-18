#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

string cipher(string, int);

int main(int argc, string argv[]){
    
    if(argc != 2){
        printf("INVALID STATEMENT\n");
        return 1;
    }
    
	int key = (int)strtol(argv[1], (char **)NULL, 10); //ASCII adjustment
	
	printf("plaintext: ");
	string message = get_string();

	printf("ciphertext: %s\n", cipher(message, key) ); //printing the encrypted message
	return 0;
}

string cipher(string message, int key){
    
	// int length = strlen(message);

	for(int i = 0; message[i] != '\0'; i++){
	
	    if( isalpha(message[i]) ){
            
            if( isupper( message[i] ) ){
            	message[i] += key; //adding key
    			while( !isalpha( message[i] )) //if exceeding ASCII, go round // for UPPER
    				message[i] -= 26;
            }
            
			else if( islower( message[i] ) ){
				message[i] += key; //adding key
        		while( !isalpha( message[i] )) //if exceeding ASCII, go round // for UPPER
    				message[i] -= 26;
			}
		}
	}
	
	return message;
}