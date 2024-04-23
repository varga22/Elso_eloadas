/*Készítsen egy programot, amely a bemeneti argumentumként kapott két egész szám között (zárt intervallumon) 
generál egy szintén egész véletlen számot! Ellenőrízze az argumentumok számát,
és jelezzen hibát, amennyiben nem megfelelőek!*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int lower_bound, upper_bound;

    // lower num
    printf("Kerem adja meg az also hatart: ");
    scanf("%d", &lower_bound);

    // upper num
    printf("Kerem adja meg a felso hatart: ");
    scanf("%d", &upper_bound);

    // check if the lower num is lower than the upper num
    if (lower_bound > upper_bound) {
        printf("Hiba: Az also hatar nagyobb, mint a felso hatar.\n");
        return 1;
    }

    // generate num between  the two bounds
    srand(time(NULL)); //initialize  random seed
    int random_number = rand() % (upper_bound - lower_bound + 1) + lower_bound;

    // output the result
    printf("A generalt veletlen szam a kovetkezo: %d\n", random_number);

    return 0;
}
