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
void basaEkle(int sayi)
{
    struct dugum *eklenecek;
    eklenecek = (struct dugum *)malloc(sizeof(struct dugum)); // yeni düğüm için bellek ayırma
    eklenecek->veri = sayi;                                   // düğüme veri atama
    eklenecek->gosterici = bas;                               // yeni düğümün göstericisi başa işaret ediyor
    bas = eklenecek;                                          // baş düğümü yeni düğüm olarak güncelleme
}
void yazdir()
{
    gecici = bas; // geçici düğüm başa eşitleniyor
    while (gecici != NULL)
    { // tüm düğümleri yazdırma
        printf("%d ", gecici->veri);
        gecici = gecici->gosterici; // bir sonraki düğüme geçme
    }
    printf("%d\n", gecici->veri); // satır sonu ekleme
}
int main()
{
    int sayi, adet = 0;
    while (adet != 5)
    {
        printf("Basa eklenecek sayiyi giriniz: \n");
        scanf("%d", &sayi); // kullanıcıdan sayı alma
        basaEkle(sayi);     // sayıyı başa ekleme
        adet++;
    }
    yazdir(); // tüm düğümleri yazdırma
}