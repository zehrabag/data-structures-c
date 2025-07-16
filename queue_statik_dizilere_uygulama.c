#include <stdio.h>
#include <stdlib.h>
#define BOY 5
// KUYRUK(QUEUE) STATIK DIZİLERLE UYGULAMA
int dizi[BOY];
int bas = -1, son = -1;
void elemanEkle(int veri)
{
    if (son == BOY - 1)
        printf("Kuyruk dolu.\n");
    else
    {
        if (son == -1)
        {
            bas = 0;
            son = 0;
            dizi[son] = veri;
        }
    }
}
void elemanCikar()
{
    if (bas == -1 || bas > son)
    {
        printf("Kuyruk bos.\n");
        bas == -1;
        son == -1;
    }
    else
    {
        bas = bas + 1;
    }
}
void yazdir()
{
    system("cls");
    if (bas == -1)
        printf("Kuyruk bos.\n");
    else
    {
        int i;
        for (i = bas; i <= son; i++)
        {
            printf("%d", dizi[i]);
        }
    }
}
int main()
{
    int secim, sayi;
    while (1)
    {
        printf("\n\tYIGIN(DYNAMIC STACK)\n");
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
            exit(0);
        default:
            printf("Gecersiz secim.\n");
        }
    }
    return 0;
}