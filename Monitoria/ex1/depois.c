#include <stdio.h>

void increment(int* count){
    *count++;
}

void decrement(int* count){
    *count--;
}

int main(void){
    int count = 0;
    increment(&count);
    printf("count: %d", count);

    decrement(&count);
    printf("count: %d", count);

    return 0;
}







