//
//  main.c
//  Collatz
//
//  Created by Eric Bjarstal on 14/02/2023.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_SEQUENCE_SIZE 1000

void collatz(long sequence[], const unsigned long n);

int main(int argc, const char * argv[]) {
    
    unsigned long userNumber = 0;
    
    printf("Enter number: ");
    scanf("%ld", &userNumber);
    
    long mySequence[MAX_SEQUENCE_SIZE] = {userNumber};
    
    collatz(mySequence, userNumber);
    
    return 0;
}

// prints Collatz sequence of given n and modifies given sequence[]
void collatz(long sequence[], const unsigned long n) {
    
    int i = 1;
    unsigned long cursor = n;
    sequence[0] = n;
    
    while (cursor != 1) {
        if (cursor % 2 == 0) {
            cursor /= 2;
            sequence[i] = cursor;
        }
        else {
            cursor = 3*cursor + 1;
            sequence[i] = cursor;
        }
        i++;
    }
    printf("Number of steps: %d\n", i-1);
    printf("Sequence: ");
    int j;
    for (j = 0; j < i-1; j++) {
        printf("%ld -> ", sequence[j]);
    }
    printf("%ld\n", sequence[i-1]);
}
