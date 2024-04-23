/*Írjon egy programot, amelyik egész értékeket ír ki pontosan 8 karakter hosszan (jobbra igazítva)! 
Oldja meg úgy, hogy szóközökkel, továbbá hogy 0 értékekkel van kitöltve a szám eleje (amennyiben szükséges kitölteni)!
*/
#include <stdio.h>

int main() {
    int number = 123;
    printf("Value: %d\n", number);
    
    printf("Value with spaces: %8d\n", number);
    
    printf("Value with zeros: %08d\n", number);
    
    return 0;
}