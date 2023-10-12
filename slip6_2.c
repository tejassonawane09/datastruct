#include <stdio.h>
void bubble_sort(int b[], int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}
void main()
{
    int a[30], n, i;
    printf("\nENTER HOW MANY NUMBERS:");
    scanf("%d", &n);
    printf("\nENTER THE ELEMENTS:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bubble_sort(a, n);
    printf("\nSORTED ELEMENTS ARE:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    getch();
}