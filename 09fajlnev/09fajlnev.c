/*Készítsen egy programot, amelyik a paraméterként vár egy fájlnevet és egy elemszámot (mint egész értéket).
Ezek alapján hozza létre a program az adott fájlt véletlenszerű értékekkel kitöltve, a megfelelő elemszámmal!
Mérje le a véletlenszámok generálásának sebességét az elemszám függvényében!
Mérje le a fájl mentésének idejét az elemszám függvényében!
Gyűjtse össze a kapott mérési adatokat táblázatba, és ábrázolja őket grafikonon!*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to measuring speed of generated numbers
double measure_random_generation_speed(int n) {
    clock_t start_time = clock();
    for (int i = 0; i < n; ++i) {
        rand();
    }
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    return elapsed_time;
}

// function to measuring speed of saving file
double measure_file_saving_time(int *numbers, int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Hiba: Nem lehet megnyitni a fajlt.\n");
        return -1.0;
    }

    clock_t start_time = clock();
    for (int i = 0; i < n; ++i) {
        fprintf(file, "%d ", numbers[i]);
    }
    clock_t end_time = clock();

    fclose(file);

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    return elapsed_time;
}

int main(int argc, char *argv[]) {
    // check the number of arguments
    if (argc != 3) {
        printf("Hasznalat: %s <fajlnev> <elemszam>\n", argv[0]);
        return 1;
    }

    // read the argv
    int n = atoi(argv[2]);

    // Generate random numbers array
    int *numbers = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        numbers[i] = rand();
    }

    // measuring speed of generated random numbers
    double random_generation_time = measure_random_generation_speed(n);
    printf("Véletlen számok generálása %d db elemre: %.6f mp\n", n, random_generation_time);

    // measuring speed of saving file
    double file_saving_time = measure_file_saving_time(numbers, n, argv[1]);
    printf("Fájl mentése %d db elemmel: %.6f mp\n", n, file_saving_time);

    // free memory
    free(numbers);

    return 0;
}
