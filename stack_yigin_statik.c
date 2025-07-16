#include <stdio.h>
#include <stdlib.h>
#define BOY 10
// STATİK
// ELEMAN EKLEME, CIKARMA, YAZDIRMA
struct yigin
{
    int dizi[BOY];
    int indis;
};
struct yigin y1;
void elemanEkle(int sayi)
{
    if (y1.indis == BOY - 1)
    {
        printf("Yigin dolu.\n");
    }
    else
    {
        y1.indis++;
        y1.dizi[y1.indis] = sayi;
    }
}
void elemanCikar()
{
    if (y1.indis == -1)
        printf("Yigin bos.\n");
    else
    {
        int cikanSayi = y1.dizi[y1.indis];
        y1.indis--;
        printf("Yigindan %d sayisi cikartildi.\n", cikanSayi);
    }
}
void yazdir()
{
    system("cls");
    if (y1.indis == -1)
    {
        printf("Yigin bos.\n");
    }
    else
    {
        for (int i = y1.indis; i >= -1; i--)
        {
            printf("%d ", y1.dizi[i]);
        }
    }
}
int main()
{
    y1.indis = -1;
    int secim, sayi;
    while (1)
    {
        printf("\n\tYIGIN(STACK)\n");
        printf("1. Eleman (push)\n");
        printf("2. Eleman Cikar(pop)\n");
        printf("3. Yigini Yazdir(display)\n");
        printf("4. Cikis(exit)\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);
        switch (secim)
        {
        case 1:
            printf("Eklenecek sayiyi giriniz: ");
            scanf("%d", &sayi);
            elemanEkle(sayi);
            break;
        case 2:
            elemanCikar();
            break;
        case 3:
            yazdir();
            break;
        case 4:
            printf("Cikis yapiliyor...\n");
            return 0;
        }
    }
    return 0;
}
