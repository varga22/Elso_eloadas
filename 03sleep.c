//Készítsen példát a sleep függvény használatára!
#include <stdio.h>
#include <unistd.h> // function sleep

int main() {
    printf("The program will sleep\n");
    
    int seconds = 5; 
    int i;
    for (i = 1; i <= seconds; ++i) {
        printf("seconds: %d\n", i);
        sleep(1); // second per wait
    }
    
    printf("The program is alive!\n");
    
    return 0;
}
