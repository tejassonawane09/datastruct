////slip 1 evaluate a given polynomial using function. (Use array)
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define Max 10
void create_poly(int s[], int n)
{
    printf("\n");
    for (; n >= 0; n--)
    {
        printf("ENTER COEFFICIENT OF X^%d=", n);
        scanf("%d", &s[n]);
    }
}
float eval_poly(int x[], int n, float val)
{
    float ans = 0;
    for (; n >= 0; n--)
        ans = ans + x[n] * pow(val, n);
    return ans;
}
void display_poly(int x[], int n)
{
    int i;
    for (i = n; i > 0; i--)
    {
        printf("%dX^%d+", x[i], i);
    }
    printf("%dX^%d", x[i], i);
}
void main()
{
    int x[Max], n;
    float val;
    // clrscr();
    printf("\nENTER THE HIGHEST DEGREE OF THE POLYNOMIAL:");
    scanf("%d", &n);
    create_poly(x, n);
    printf("\nENTER THE VALUE OF X:");
    scanf("%f", &val);
    printf("\nTHE POLYNOMAIL IS:");
    display_poly(x, n);
    printf("\nTHE POLYNOMIAL EVALUATES TO :%.3f", eval_poly(x, n, val));
    getch();
}