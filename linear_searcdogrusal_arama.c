#include <stdio.h>
#include <stdlib.h>
// ARAMA LİNEAR SEARCH (DOĞRUSAL)
// BASTAN BASLAYARAK ARANAN SAYIYI KIYASLAR
// VARSA İNDİSİ DÖNDÜR YOKSA -1 DÖNDÜR
int linearSearch(int dizi[], int n, int aranan)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (aranan == dizi[i])
            return i;
    }
    return -1;
}
int main()
{
    int n;
    printf("Dizinin boyutunu giriniz: ");
    scanf("%d ", &n);
    // int dizi[n];
    int *dizi = (int *)malloc(n * sizeof(int));
    int i = 0;
    while (i < n)
    {
        printf("Sayi: ");
        scanf("%d", &dizi[i]);
        i++;
    }
    printf("Aranan sayiyi giriniz: ");
    int aranan;
    scanf("%d ", &aranan);
    int sonuc = linearSearch(dizi, n, aranan);
    if (sonuc == -1)
        printf("Aranan sayi dizide yok.\n");
    else
        printf("Aranan sayi dizide var.\n");
    return 0;
}