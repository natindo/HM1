#include <stdio.h>
#include <math.h>

int main() {

    char c;
    char a[64] = {};
    int i = 0;

    while ((c = getchar()) != '\n' && i<=64)
        a[i++] = c;

    int counter = 0;

    while (a[counter] != '|') {
        counter++;
    }

    double res, res1 = 0;
    i = counter - 1;
    int g = 0;

    while (i >= 0) {
        res1 = pow(10, g) * (a[i] - '0');
        i--;
        g++;
    }

    g = 1;
    counter++;
    double basis = 0.1;

    while (a[counter] != '\0') {
        res = res1 + pow(basis, g) * (a[counter] - '0');
        //printf ("%lf\n", pow((0,1), (g)));
        //printf ("%d\n", counter);
        counter++;
        g++;
    }

    printf("%g", res);

    return 0;
}
