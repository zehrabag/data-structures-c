#include <stdio.h>
#include <stdlib.h>
// SEÇMELİ SIRALAMA SELECTİON SORT
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i; j < n; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }
}
void yazdir(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
int main()
{
    int arr[] = {1, 5, 0, 4, 6, 9, 8, 2, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    yazdir(arr, n);
    return 0;
}