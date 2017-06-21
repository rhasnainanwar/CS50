/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(n > 0){
        int start = 0;
        int end  = n - 1;
        int middle = (start + end)/2;
        
        while(start <= end){
            if(values[middle] == value)
                return true;
            else if(values[middle] < value)
                start = middle + 1;
            else
                end = middle - 1;
                
            middle = (start + end)/2;
        }
    }
    //default
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    int temp = 0; //temporary variable for swapping
    
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; ++j)
            if(values[j] > values[j+1]){
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
    }

    return;
}
