#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main() {

    char c;
    char a[64] = {};
    int i = 0, j = 0;
    //Reading the data
    while ((c = getchar()) != '\n') {
        a[i++] = c;
        if (i > 64) { //Checking the correctness of the string length
            printf("Введены слышком большие значения\n");
            return 1;
        }
    }

    while (j != i) {
        if (isdigit(a[j]) == 0 || a[j] != '|') {
            printf("%c\n", a[j]);
            printf("Не вводите буквы\n");
            return 3;
        }
        j++;
    } 

    int counter = 0;

    while (a[counter] != '|') {
        counter++;
    }

    if(counter = i) {
        printf ("Не была введена вертикальная черта\n");
        return 2;
    }

    double res = 0, res1 = 0;
    i = counter - 1;
    int g = 0;

    while (i >= 0) {
        res1 = res1 + (pow(10, g) * (a[i] - '0'));
        i--;
        g++;
    }

    g = 1;
    counter++;
    double basis = 0.1;

    while (a[counter] != '\0') {
        res = res1 + (pow(basis, g) * (a[counter] - '0'));
        counter++;
        g++;
    }

    printf("%g\n", res);

    return 0;
}
