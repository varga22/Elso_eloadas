/*Definiáljon egy függvényt, amely az [1,n]
intervallumon meghatározza a prímszámok számát!
Mérje le a futási időt az n = 1000, 2000, 3000,  ..., 20000 értékeknél, és jelenítse meg grafikonon a kapott eredményeket (például Excel-el)!*/
#include <stdio.h>
#include <time.h>

// function, that provides the number of prime numbers in an interval from [1, n] 
int count_primes(int n) {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        int is_prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            count++;
        }
    }
    return count;
}

int main() {
    int n_values[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000};
    int n_values_count = sizeof(n_values) / sizeof(n_values[0]);

    printf("n\tPrimes\tTime (sec)\n");
    for (int i = 0; i < n_values_count; i++) {
        int n = n_values[i];
        clock_t start_time = clock();
        int primes_count = count_primes(n);
        clock_t end_time = clock();
        double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("%d\t%d\t%.6f\n", n, primes_count, elapsed_time);
    }

    return 0;
}
