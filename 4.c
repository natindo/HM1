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
            printf("Введено слышком много цифр\n");
            return 1;
        }
    }

    while (j != i) {
        if (isdigit(a[j]) == 0 && a[j] != '|') { //Checking for the input of letters or characters other than |
            printf("Не вводите буквы или другие специальные символы, кроме |\n");
            return 3;
        }
        j++;
    } 

    int counter = 0;

    while (a[counter] != '|') {
        counter++;
    }

    if(counter == i) { //Checking for input |
        printf ("Не была введена вертикальная черта\n");
        return 2;
    }

    double res = 0, res1 = 0;
    i = counter - 1;
    int g = 0;

    while (i >= 0) { //Counting the integer part
        res1 = res1 + (pow(10, g) * (a[i] - '0'));
        i--;
        g++;
    }

    g = 1;
    counter++;
    double basis = 0.1;

    while (a[counter] != '\0') { //Counting the fractional part
        res = res + (pow(basis, g) * (a[counter] - '0'));
        counter++;
        g++;
    }

    res = res + res1;
    g--;

    printf("%.*f\n", g, res);

    return 0;
}
