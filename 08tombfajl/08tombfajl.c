/*Írjon egy programot, amely egy tömbben lévő értékeket kiírja egy fájlba!
A műveletet szervezze ki egy külön függvénybe!
Készítse el int, long és float típusok esetére is (külön függvényekkel)!
Kérdezze le, hogy az adott útvonalon lévő fájlnak mekkora a mérete!
Készítse el a függvényeket az adatok visszaolvasásához!*/

#include <stdio.h>
#include <stdlib.h>

// Function to write int array to file
void write_int_array_to_file(const char *filename, int *array, int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Hiba: Nem lehet megnyitni a fajlt.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", array[i]);
    }

    fclose(file);
}

// Function to write long array to file
void write_long_array_to_file(const char *filename, long *array, int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Hiba: Nem lehet megnyitni a fajlt.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%ld ", array[i]);
    }

    fclose(file);
}

// Function to write float array to file
void write_float_array_to_file(const char *filename, float *array, float size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Hiba: Nem lehet megnyitni a fajlt.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%f ", array[i]);
    }

    fclose(file);
}

// function to wirte file size
long getFileSize(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Hiba: Nem lehet megnyitni a fajlt.\n");
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);

    return size;
}

// function to  read array from file
void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Hiba: Nem lehet megnyitni a fajlt.\n");
        return;
    }

    int value;
    while (fscanf(file, "%d", &value) == 1) {
        printf("%d ", value);
    }

    fclose(file);
}
// special function to read float array from file
void readFloatFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Hiba: Nem lehet megnyitni a fajlt.\n");
        return;
    }

    float value;
    while (fscanf(file, "%f", &value) == 1) {
        printf("%f ", value);
    }
    printf("\n");

    fclose(file);
}

int main() {
    // Write int data to file
    int int_array[] = {1, 2, 3, 4, 5};
    write_int_array_to_file("int.txt", int_array, sizeof(int_array) / sizeof(int_array[0]));

    // Write long data to file
    long long_array[] = {1000000000L, 2000000000L, 123456789L, 987654321L};
    write_long_array_to_file("long.txt", long_array, sizeof(long_array) / sizeof(long_array[0]));

    // Write float data to file
    float float_array[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    write_float_array_to_file("float.txt", float_array, sizeof(float_array) / sizeof(float_array[0]));

    // Getting file size
    printf("\nint.txt merete: %ld byte\n", getFileSize("int.txt"));
    printf("long.txt merete: %ld byte\n", getFileSize("long.txt"));
    printf("float.txt merete: %ld byte\n", getFileSize("float.txt"));

    // Read from file
    printf("\nAdatok az int.txt fajlbol: ");
    readFile("int.txt");

    printf("\nAdatok a long.txt fajlbol: ");
    readFile("long.txt");

    printf("\nAdatok a float.txt fajlbol: ");
    readFloatFile("float.txt");

    return 0;
}
