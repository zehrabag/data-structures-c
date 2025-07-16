#include <stdio.h>
#include <stdlib.h>
// OUICK SORT(HIZLI)
// 1 - PİVOT BELİRLE (ORTANCA SAYI)
// 2 - İŞLEM REQURSİVE (ÖZYİNELİ)OLARAK DEVAM EDECEK
void quickSort(int dizi[], int bas, int son)
{
    int i, j, pivot, temp;
    i = bas;
    j = son;
    pivot = dizi[(i + j) / 2];
    do
    {
        while (dizi[i] < pivot)
            i++;
        while (dizi[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = dizi[i];
            dizi[i] = dizi[j];
            dizi[j] = temp;
            i++;
            j--;
        }
    } while (i < j);
    if (i < son)
        quickSort(dizi, i, son);
    if (bas < j)
        quickSort(dizi, bas, j);
}
int main()
{
    int n;
    printf("Dizi boyunu giriniz: ");
    scanf("%d ", &n);
    // int dizi[n];
    int *dizi = (int *)malloc(n * sizeof(int));
    int i = 0;
    while (i < n)
    {
        printf("Sayi: ");
        scanf("%d ", &dizi[i]);
        i++;
    }
    quickSort(dizi, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        printf("%d ", dizi[n]);
    }
    return 0;
}