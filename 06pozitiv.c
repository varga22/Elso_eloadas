/*Írjon egy programot, amelyik 2 véletlenszerűen meghatározott pozitív egész szám értékét számoltatja ki a felhasználóval, 
és a szabványos bemeneten várja az eredményt! 
Ellenőrízze, hogy helyes az érték, és írja ki, hogy mennyi ideig tartott (másodpercben) a felhasználónak a számítás!*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // this is the  seed for generating random numbers, it can be any
    int num1, num2, result;
    clock_t start_time, end_time;
    double elapsed_time;

    // generate a random num
    srand(time(NULL));
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    // type the result
    printf("Kerem adja meg a(z) %d + %d eredmenyet: ", num1, num2);
    start_time = clock(); // time measurement starts here
    scanf("%d", &result);
    end_time = clock(); // time  measurement ends here

    // check the result
    if (result == num1 + num2) {
        printf("Helyes eredmeny!\n");
    } else {
        printf("Hibas eredmeny!\n");
    }

    // calculate the elapsed time
    elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Az ellenorzes %lf masodpercig tartott.\n", elapsed_time);

    return 0;
}
