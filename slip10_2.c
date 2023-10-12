#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// Function to display array
void DisplayArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf(" %d ", arr[i]);
}
// Function to generate random array
void Generate(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        arr[i] = rand() % 100;
}
// Function for insertion sort
void InsertionSort(int arr[], int n)
{
    int Rvalue, i, j;
    for (i = 1; i < n; i++)
    {
        Rvalue = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > Rvalue)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = Rvalue;
    }
}
// main() function to test the insertion sort

void main()
{
    int arr[100], n;
    printf("\n Enter the size of array:- ");
    scanf("%d", &n);
    Generate(arr, n); // Generating a random array

    printf("\n The random array: ");
    DisplayArray(arr, n);  // Displaying the array
    InsertionSort(arr, n); // Sorting the array
    printf("\n The sorted array: ");
    DisplayArray(arr, n); // Displaying the sorted array
    printf("\n");
}