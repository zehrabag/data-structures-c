#include <stdio.h>
#include <stdlib.h>
// TEK YÖNLÜ DAİRESEL BAĞLI LİSTE BAŞA-SONA ELEMAN EKLEME
// BASTAN SİLME - SONDAN ELEMAN SİLME
// ELEMAN ADETİ
// DATALARIN TOPLAMI
// LİSTELEME
struct node
{
    int data;          // veri alanı
    struct node *next; // sonraki düğümü işaret eden gösterici
};
struct node *start = NULL;
struct node *temp = NULL;
struct node *prev = NULL;
struct node *last = NULL;
void basaEkle(int veri)
{
    struct node *eleman;
    eleman = (struct node *)malloc(sizeof(struct node)); // yeni düğüm için bellek ayırma
    eleman->data = veri;                                 // düğüme veri atama
    if (start == NULL)
    {
        start = eleman;
        start->next = start;
    }
    else
    {
        temp = start;
        while (temp->next != start)
        {
            temp = temp->next; // son düğüme kadar ilerleme
        }
        temp->next = eleman;  // son düğümün göstericisini yeni düğüme yönlendirme
        eleman->next = start; // yeni düğümün göstericisi başa
        start = eleman;       // baş düğümü yeni düğüm olarak güncelleme
    }
}
void sonaEkle(int veri)
{
    struct node *eleman;
    eleman = (struct node *)malloc(sizeof(struct node)); // yeni düğüm için bellek ayırma
    eleman->data = veri;                                 // düğüme veri atama
    if (start == NULL)
    {
        start = eleman;
        start->next = start; // ilk düğüm
    }
    else
    {
        temp = start; // geçici düğüm başa eşitleniyor
        while (temp->next != start)
        {
            temp = temp->next; // son düğüme kadar ilerleme
        }
        temp->next = eleman;  // son düğümün göstericisini yeni düğüme yönlendirme
        eleman->next = start; // yeni düğümün göstericisi başa
    }
}
void bastanSil()
{
    if (start == NULL)
    {
        printf("Liste bos.\n");
    }
    else
    {
        if (start->next == start)
        {
            free(start);
            start = NULL;
        }
        else
        {
            last = start;
            while (last->next != start)
            {
                last = last->next; // son düğüme kadar ilerleme
            }
            temp = start->next; // baş düğümden sonraki düğümü geçici düğüme atama
            free(start);        // baş düğümü serbest bırakma
            last->next = temp;  // son düğümün göstericisini yeni baş düğüm olarak güncelleme
            start = temp;       // baş düğümü yeni baş düğüm olarak güncelle
        }
    }
}
void sondanSil()
{
    if (start == NULL)
    {
        printf("Liste bos.\n");
    }
    else
    {
        if (start->next == start)
        {
            free(start);
            start = NULL;
        }
        else
        {
            last = start;
            while (last->next->next != start)
            {
                last = last->next; // son düğüme kadar ilerleme
            }
            free(last->next);   // son düğümü serbest bırakma
            last->next = start; // son düğümün göstericisini başa yönlendirme
        }
    }
}
int elemanSay()
{
    int adet = 0;
    if (start == NULL)
        return 0;
    else
    {
        temp = start;
        while (temp->next != start)
        {
            adet++;
            temp = temp->next; // tüm düğümleri sayma
        }
        adet++; // son düğümü de sayma
    }
    return adet;
}
int dataToplam()
{
    int toplam = 0;
    if (start == NULL)
        return 0;
    else
    {
        temp = start;
        while (temp->next != start)
        {
            toplam += temp->data; // tüm düğümlerin verilerini toplama
            temp = temp->next;    // bir sonraki düğüme geçme
        }
        toplam += temp->data; // son düğümün verisini de ekleme
    }
    return toplam;
}
void listele()
{
    system("cls"); // ekranı temizleme
    if (start == NULL)
    {
        printf("Liste bos.\n");
    }
    else
    {
        temp = start; // geçici düğüm başa eşitleniyor
        while (temp->next != start)
        {
            printf("%d -> ", temp->data); // tüm düğümleri yazdırma
            temp = temp->next;            // bir sonraki düğüme geçme
        }
        printf("%d ", temp->data);
    }
}
int main()
{
    while (1)
    {
        int secim, sayi;
        printf("\n1-->Basa eleman eklemek icin: \n");
        printf("2-->Sona eleman eklemek icin: \n");
        printf("3-->Bastan eleman silmek icin: \n");
        printf("4-->Sondan eleman silmek icin: \n");
        printf("5-->Eleman sayisini ogrenmek icin: \n");
        printf("6-->Data toplamini ogrenmek icin: \n");
        printf("7-->Listeyi gormek icin: \n");
        printf("Yapmak istedifginiz secimi giriniz: \n");
        scanf("%d", &secim);
        switch (secim)
        {
        case 1:
            printf("Basa eklenecek sayiyi giriniz: ");
            scanf("%d", &sayi); // kullanıcıdan sayı alma
            basaEkle(sayi);     // sayıyı başa ekleme
            break;
        case 2:
            printf("Sona eklenecek sayiyi giriniz: ");
            scanf("%d", &sayi); // kullanıcıdan sayı alma
            sonaEkle(sayi);     // sayıyı sona ekleme
            break;
        case 3:
            bastanSil(); // baştan eleman silme
            break;
        case 4:
            sondanSil(); // sondan eleman silme
            break;
        case 5:
            printf("Eleman sayisi: %d\n", elemanSay()); // eleman
            break;
        case 6:
            printf("Data toplami: %d\n", dataToplam()); // data toplami
            break;
        case 7:
            listele(); // listeyi yazdırma
            break;
        }
    }
    return 0;
}