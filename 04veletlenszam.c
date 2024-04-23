/*Generáljon véletlenszámot az [500, 1000] intervallumon! 
(Oldja meg lebegőpontos és egész számok esetére is!) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // seed

    // generate random num between 500,1000
    int random_int = rand() %  (1000 - 500 + 1) + 500;
    float random_float = 500.0f + ((float)rand() / RAND_MAX) * (1000.0f - 500.0f);
    
    printf("Number int: %d\n", random_int);
    printf("Number fpu: %.2f\n", random_float);
    
    return 0;
}
