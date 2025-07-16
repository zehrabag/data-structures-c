#include <stdio.h>
#include <stdlib.h>
// veri girişi
struct dugum // yapı oluşturma
{
    int veri;
    struct dugum *gosterici;
};
struct dugum *bas = NULL;
struct dugum *gecici = NULL;
void sonaEkle(int sayi)
{
    struct dugum *eklenecek;
    eklenecek = (struct dugum *)malloc(sizeof(struct dugum)); // yeni düğüm için bellek ayırma
    eklenecek->veri = sayi;                                   // düğüme veri atama
    eklenecek->gosterici = NULL;                              // son düğümün göster
    if (bas == NULL)
    {
        bas = eklenecek; // ilk düğüm
    }
    else
    {
        gecici = bas; // geçici düğüm başa eşitleniyor
        while (gecici->gosterici != NULL)
        { // son düğüme kadar ilerleme
            gecici = gecici->gosterici;
        }
        gecici->gosterici = eklenecek; // son düğümün göstericisini yeni düğüme yönlendirme
    }
}
void yazdir()
{
    gecici = bas; // geçici düğüm başa eşitleniyor
    while (gecici != NULL)
    { // tüm düğümleri yazdırma
        printf("%d ", gecici->veri);
        gecici = gecici->gosterici; // bir sonraki düğüme geçme
    }
    printf("%d ", gecici->veri); // son düğümün verisini yazdırma
}
int main()
{
    int adet = 0;
    while (adet != 5)
    {
        int sayi;
        printf("Sona eklenecek sayiyi giriniz: ");
        scanf("%d", &sayi); // kullanıcıdan sayı alma
        sonaEkle(sayi);     // sayıyı sona ekleme
        adet++;
    }
    yazdir(); // tüm düğümleri yazdırma
}