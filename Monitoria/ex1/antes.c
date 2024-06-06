#include <stdio.h>

int count;

void increment(){
    count++;
}

void decrement(){
    count--;
}

int main(void){
    count = 0;
    increment();
    printf("count: %d", count);

    decrement();
    printf("count: %d", count);

    return 0;
}







