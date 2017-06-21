#include <stdio.h>

int main(){
    int temp, digit, num,sum = 0;

    for(num = 100; num <= 999; num++){
        temp = num;
        sum = 0;

        while(temp != 0){
            digit = temp % 10;
            sum = sum + (digit * digit * digit);
            temp /= 10;
        }

        if(sum == num)
            printf("%d is an Armstrong number.\n", num);

    }

    return 0;
}
