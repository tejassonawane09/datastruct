// insertion sort
#include <stdio.h>
void insertion_sort(int b[20], int size)
{
    int i, j, temp;
    for (i = 1; i < size; i++)
    {
        temp = b[i];
        j = i - 1;
        while (j >= 0 && b[j] > temp)
        {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = temp;
    }
}
void main()
{
    int a[20], n, i;
    printf("\nENTER HOW MANY ELEMENTS:");
    scanf("%d", &n);
    printf("\nENTER THE ELEMENTS:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    insertion_sort(a, n);
    printf("\n----------SORTED DATA USING INSERTION SORT----------\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    getch();
}