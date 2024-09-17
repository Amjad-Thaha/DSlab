#include <stdio.h>

struct Polynomial {
    int coeff;
    int exp;
};

int main() {
    int n, m, i, j, k = 0;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    struct Polynomial poly1[n];
    printf("Enter the coefficients and exponents of the first polynomial:\n");
    for (i = 0; i < n; i++) {
        printf("Term %d:\n", i+1);
        scanf("%d %d", &poly1[i].coeff, &poly1[i].exp);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &m);
    struct Polynomial poly2[m];
    printf("Enter the coefficients and exponents of the second polynomial:\n");
    for (i = 0; i < m; i++) {
        printf("Term %d:\n", i+1);
        scanf("%d %d", &poly2[i].coeff, &poly2[i].exp);
    }

    struct Polynomial result[n + m];
    for (i = 0; i < n; i++) {
        result[k] = poly1[i];
        k++;
    }
    for (i = 0; i < m; i++) {
        result[k] = poly2[i];
        k++;
    }

    for (i = 0; i < k; i++) {
        for (j = i + 1; j < k; j++) {
            if (result[i].exp == result[j].exp) {
                result[i].coeff += result[j].coeff;
                for (int l = j; l < k; l++) {
                    result[l] = result[l + 1];
                }
                k--;
                j--;
            }
        }
    }

    printf("Resultant polynomial:\n");
    for (i = 0; i < k; i++) {
        printf("%dx^%d ", result[i].coeff, result[i].exp);
        if (i < k - 1) {
            printf("+ ");
        }
    }
    printf("\n");

    return 0;
}
