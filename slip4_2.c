#include <stdio.h>
#include <conio.h>
#define max 10
void create_poly(int s[], int n)
{
    for (; n >= 0; n--)
    {
        printf("ENTER COEFFICIENT OF X^%d:", n);
        scanf("%d", &s[n]);
    }
}
void add_poly(int a[], int b[], int n, int m, int c[])
{
    int i;
    if (n > m)
    {
        for (i = n; i > m; i--)
            c[i] = a[i];
    }
    else
    {
        for (i = m; i > n; i--)
            c[i] = b[i];
    }
    for (; i >= 0; i--)
        c[i] = a[i] + b[i];
}
void display_poly(int x[], int n)
{
    for (; n > 0; n--)
        printf("%2dX^%d+", x[n], n);
    printf("%2dX^%d", x[n], n);
}
int main()
{
    int x[max], y[max], z[max], n, m;
    printf("\nENTER THE HIGHEST DEGREE OF FIRST POLYNOMIAL:");
    scanf("%d", &n);
    create_poly(x, n);

    printf("\nENTER THE HIGHEST DEGREE OF SECOND POLYNOMIAL:");
    scanf("%d", &m);
    create_poly(y, m);

    add_poly(x, y, n, m, z);

    printf("\nTHE FIRST POLYNOMIAL IS:");
    display_poly(x, n);

    printf("\nTHE SECOND POLYNOMIAL IS:");
    display_poly(y, m);

    printf("\nTHE ADDITION OF POLYNOMIAL:");
    if (n > m)
        display_poly(z, n);
    else
        display_poly(z, m);
    return (0);
}