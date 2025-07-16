#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// ARAMA BİNARY SEARCH (İKİLİ)
int binarySearch(int dizi[], int bas, int son, int aranan)
{
    while (son >= bas)
    {
        int orta = dizi[(bas + son) / 2];
        if (orta == aranan)
            return true;
        if (orta < aranan)
            bas++;
        if (orta > aranan)
            son--;
    }
    return false;
}
int main()
{
    int n;
    printf("Dizinin boyutunu giriniz: \n");
    scanf("%d ", &n);
    // int dizi[n];
    int *dizi = (int *)malloc(n * sizeof(int));
    int i = 0;
    while (i < n)
    {
        printf("Sayi: \n");
        scanf("%d ", &dizi[i]);
        i++;
    }
    int aranan;
    printf("Aranan Sayiyiy giriniz: \n");
    scanf("%d ", &aranan);
    bool sonuc = binarySearch(dizi, 0, n - 1, aranan);
    if (sonuc == true)
        printf("Aranan sayi dizide var.\n");
    else
        printf("Aranan sayi dizide yok.\n");
    return 0;
}