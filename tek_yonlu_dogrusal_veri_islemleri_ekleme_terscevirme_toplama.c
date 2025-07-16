#include <stdio.h>
#include <stdlib.h>
// TEK YÖNLÜ DOĞRUSAL BAĞLI LİSTE BAŞA-SONA ELEMAN EKLEME
// BASTAN SİLME - SONDAN ARADAN ELEMAN SİLME
// TERS CEVİRME
// ELEMAN ADETİ
// DATALARIN TOPLAMI

struct node
{
    int data;          // veri alanı
    struct node *next; // sonraki düğümü işaret eden gösterici
};
struct node *start = NULL;
struct node *temp = NULL;
void basaEkle(int veri)
{
    struct node *eleman;
    eleman = (struct node *)malloc(sizeof(struct node)); // yeni düğüm için bellek ayırma
    eleman->data = veri;                                 // düğüme veri atama
    eleman->next = start;                                // yeni düğümün göstericisi başa işaret ediyor
    start = eleman;                                      // baş düğümü yeni düğüm olarak güncelleme
}
void sonaEkle(int veri)
{
    struct node *eleman;
    eleman = (struct node *)malloc(sizeof(struct node)); // yeni düğüm için bellek ayırma
    eleman->data = veri;                                 // düğüme veri atama
    eleman->next = NULL;                                 // son düğümün göstericisi NULL
    if (start == NULL)
    {
        start = eleman; // ilk düğüm
    }
    else
    {
        temp = start; // geçici düğüm başa eşitleniyor
        while (temp->next != NULL)
        { // son düğüme kadar ilerleme
            temp = temp->next;
        }
        temp->next = eleman; // son düğümün göstericisini yeni düğüme yönlendirme
    }
}
void arayaEkle(int n, int veri)
{
    struct node *eleman;
    eleman = (struct node *)malloc(sizeof(struct node)); // yeni düğüm için bellek ayırma
    eleman->data = veri;                                 // düğüme veri atama
    temp = start;                                        // geçici düğüm başa eşitleniyor
    while (temp->next->data != n)
    {
        temp = temp->next; // n değerine kadar ilerleme
    }
    struct node *temp2;
    temp2 = (struct node *)malloc(sizeof(struct node)); // yeni düğüm için bellek ayırma
    temp2 = temp->next;
    temp->next = eleman;  // yeni düğümün göstericisi n değerine işaret ediyor
    eleman->next = temp2; // yeni düğümün göstericisi n değer
}
void bastanSil()
{
    if (start != NULL)
    {
        temp = start->next;
        free(start);  // baş düğümü serbest bırakma
        start = temp; // baş düğümü yeni baş düğüm olarak güncelleme
    }
    else
        free(start); // liste boşsa hata mesajı
}
void sondanSil()
{
    if (start->next != NULL)
    {
        temp = start;
        while (temp->next->next != NULL)
        {
            temp = temp->next; // son düğüme kadar ilerleme
        }
        free(temp->next);  // son düğümü silme
        temp->next = NULL; // son düğümün göstericisini NULL yapma
    }
    else
        bastanSil(); // liste boşsa hata mesajı
}
void aradanSil(int veri)
{
    temp = start;
    if (temp->data == veri)
    {
        bastanSil(); // baştan silme işlemi
    }
    else
    {
        struct node *temp2;
        temp2 = (struct node *)malloc(sizeof(struct node)); // yeni düğüm için bel
        while (temp->next->data != veri)
        {
            temp = temp->next; // n değerine kadar ilerleme
        }
        if (temp->next->next != NULL)
        {
            sondanSil(); // son düğümü silme işlemi
        }
        else
        {
            temp2 = temp->next->next;
            free(temp->next);   // silinecek düğümü serbest bırakma
            temp->next = temp2; // silinen düğümün göstericisini güncelleme
        }
    }
}
void tersCevir()
{
    struct node *temp2 = NULL;
    struct node *prev = NULL;
    temp = start;
    while (temp != NULL)
    {
        temp2 = temp->next;
        temp->next = prev;
        prev = temp;
        temp = temp2; // bir sonraki düğüme geçme
    }
    start = prev; // baş düğümü yeni baş düğüm olarak güncelleme
}
int elemanSay()
{
    int adet = 0;
    if (start == NULL)
        return adet;
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            adet++;
            temp = temp->next; // tüm düğümleri sayma
        }
        adet++;
        return adet;
    }
}
int dataToplam()
{
    int toplam = 0;
    if (start == NULL)
        return 0;
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            toplam += temp->data; // tüm düğümlerin verilerini toplama
            temp = temp->next;    // bir sonraki düğüme geçme
        }
        toplam += temp->data; // son düğümün verisini de ekleme
    }
    return toplam;
}
void yazdir()
{
    system("cls"); // ekranı temizleme
    if (start == NULL)
    {
        temp = start;
        while (temp != NULL)
        {
            printf("%d ", temp->data); // tüm düğümleri yazdırma
            temp = temp->next;         // bir sonraki düğüme geçme
        }
        printf("%d \n", temp->data); // son düğümün verisini yazdırma
    }
    else
        printf("Eleman yok.\n"); // liste boşsa mesaj
}
int main()
{
    int sayi, adet = 0, secim, n;
    while (adet != 5)
    {
        printf("Basa eleman eklemek icin          1: \n");
        printf("Sona eleman eklemek icin          2: \n");
        printf("Araya eleman eklemek icin         3: \n");
        printf("Bastan eleman silmek icin         4: \n");
        printf("Sondan eleman silmek icin         5: \n");
        printf("Aradan eleman silmek icin         6: \n");
        printf("Elemanlari ters cevirmek icin     7: \n");
        printf("Eleman adetini bulmak icin        8: \n");
        printf("Datalarin toplami icin            9: \n");
        printf("Seciminizi yapiniz: \n");
        scanf("%d", &secim);
        switch (secim)
        {
        case 1:
            printf("Basa eklenecek sayiyi giriniz: \n");
            scanf("%d", &sayi); // kullanıcıdan sayı alma
            basaEkle(sayi);     // sayıyı başa ekleme
            yazdir();           // tüm düğümleri yazdırma
            break;
        case 2:
            printf("Sona eklenecek sayiyi giriniz: \n");
            scanf("%d", &sayi); // kullanıcıdan sayı alma
            sonaEkle(sayi);     // sayıyı sona ekleme
            yazdir();           // tüm düğümleri yazdırma
            break;
        case 3:
            printf("Hangi sayidan once: \n");
            scanf("%d", &n);
            printf("Araya eklenecek sayinin degerini giriniz: \n");
            scanf("%d", &sayi); // kullanıcıdan n değeri alma
            arayaEkle(n, sayi); // sayıyı araya ekleme
            yazdir();           // tüm düğümleri yazdırma
            break;
        case 4:
            bastanSil(); // baştan silme işlemi
            yazdir();
            break;
        case 5:
            sondanSil(); // sondan silme işlemi
            yazdir();
            break;
        case 6:
            printf("Aradan silinecek elemanin degerini giriniz: \n");
            scanf("%d", &sayi); // kullanıcıdan sayı alma
            aradanSil(sayi);    // aradan silme işlemi
            yazdir();
            break;
        case 7:
            printf("Elemanlar ters ceviriliyor.\n");
            tersCevir(); // listeyi ters çevirme işlemi
            yazdir();    // tüm düğümleri yazdırma
            break;
        case 8:
            printf("\nEleman adedi: %d\n\n", elemanSay());
            break;
        case 9:
            printf("\nDatalarin toplami: %d\n\n", dataToplam());
            break;
        }
        adet++;
    }
}