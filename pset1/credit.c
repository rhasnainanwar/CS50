#include <stdio.h>
#include <cs50.h>

int count_digits(long long number){
    int count = 0;
    while(number != 0)
    {
        number /= 10;
        ++count;
    }
    return count;
}

int main(void){
    
    printf("Number: ");
    long long number = get_long_long();
    
    int sum = 0; //overall sum
    int sum_2 = 0; //sum of digits multiplied by 2
    int n = count_digits( number );
    int digits[n];
    
    for(int i = n - 1; i >= 0; i--){ //dividing number into an array of digits
        digits[i] = number%10;
        
        if(i % 2 != 0){
            digits[i] *= 2;
            sum_2 += digits[i]%10 + digits[i]/10;
            
            digits[i] /= 2;//restoring the digit to its original form to be used for detecting which CARD
        }
        else
            sum += digits[i];
        
        number /= 10LL;
    }
    
    sum += sum_2; //overall sum
    
    if(sum % 10 == 0){
        if(digits[0] == 3 && ( digits[1] == 4 || digits[1] == 7))
            printf("AMEX\n");
        else if(digits[0] == 5 && ( digits[1] == 1 || digits[1] == 2 || digits[1] == 3 || digits[1] == 4 || digits[1] == 5))
            printf("MASTERCARD\n");
        else if(digits[0] == 4)
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");
}