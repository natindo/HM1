#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main() {

    char c;
    char a[64] = {};
    int i = 0, j = 0;
    //Reading the data
    printf("Введите строку максимальной длиной в 64 символа\n");

    while ((c = getchar()) != '\n') {
        a[i++] = c;
        if (i > 63) { //Проверка на длину строки
            printf("Введено слышком много цифр\n");
            return 1;
        }
    }

    while (j != i) {
        if (isdigit(a[j]) == 0 && a[j] != '|') { //Проверка на ввод букв или символов, отличных от |
            printf("Не вводите буквы или другие специальные символы, кроме |\n");
            return 3;
        }
        j++;
    } 

    int counter = 0;

    while (a[counter] != '|') {
        counter++;
    }

    if(counter == i) { //Проверка на ввод |
        printf ("Не была введена вертикальная черта\n");
        return 2;
    }

    double res = 0, res1 = 0;
    i = counter - 1;
    int g = 0;

    while (i >= 0) { //Подсчёт целой части числа
        res1 = res1 + (pow(10, g) * (a[i] - '0'));
        i--;
        g++;
    }

    g = 1;
    counter++;
    double basis = 0.1;

    while (a[counter] != '\0') { //Подсчёт дробной части числа
        res = res + (pow(basis, g) * (a[counter] - '0'));
        counter++;
        g++;
    }

    res = res + res1;
    g--;

    printf("%.*f\n", g, res);

    return 0;
}
