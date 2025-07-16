#include <stdio.h>
#include <stdlib.h>
// CİFT YÖNLÜ DOGRUSAL BAĞLI LİSTE BAŞA-SONA ELEMAN EKLEME
// BASTAN SİLME - SONDAN ELEMAN SİLME
// ELEMAN ADETİ
// DATALARIN TOPLAMI
// LİSTELEME
struct node
{
    int data;          // veri alanı
    struct node *next; // sonraki düğümü işaret eden gösterici
    struct node *prev; // önceki düğümü işaret eden gösterici
};
struct node *start = NULL;
struct node *temp = NULL;
struct node *prev = NULL;
struct node *temp2 = NULL;
struct node *next = NULL;
void basaEkle(int sayi)
{
    struct node *eleman = (struct node *)malloc(sizeof(struct node)); // yeni düğüm için bellek ayırma
    eleman->prev = NULL;
    eleman->data = sayi; // düğüme veri atama,
    if (start == NULL)
    {
        start = eleman;
        start->next = NULL;
    }
    else
    {
        eleman->next = start; // yeni düğümün göstericisi başa işaret ediyor
        start = eleman;
    }
}
void sonaEkle(int sayi)
{
    struct node *eleman = (struct node *)malloc(sizeof(struct node)); // yeni düğüm için bellek ayırma
    eleman->data = sayi;
    eleman->next = NULL; // son düğümün göstericisi NULL
    if (start == NULL)
    {
        start = eleman; // ilk düğüm
        start->next = NULL;
        start->prev = NULL;
    }
    else
    {
        if (start->next == NULL)
        {
            start->next = eleman;
            eleman->prev = start;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next; // son düğüme kadar ilerleme
            }
            temp->next = eleman;
            eleman->prev = temp;
        }
    }
}
void bastanSil()
{
    if (start == NULL)
    {
        printf("Liste zaten bos.\n");
    }
    else
    {
        if (start->next == NULL)
        {
            free(start);
            start = NULL;
        }
        else
        {
            temp = start->next; // baş düğümden sonraki düğümü geçici düğüme atama
            free(start);        // baş düğümü serbest bırakma
            temp->prev = NULL;  // yeni baş düğümün önceki düğümü NULL yapma
            start = temp;       // baş düğümü yeni baş düğüm olarak güncelle
        }
    }
}
void sondanSil()
{
    if (start == NULL)
    {
        printf("liste bos.\n");
    }
    else
    {
        if (start->next == NULL)
        {
            free(start);
            start = NULL; // liste boşsa başı NULL yapma
        }
        else
        {
            temp = start;
            while (temp->next->next != NULL)
            {
                temp = temp->next; // son düğüme kadar ilerleme
            }
            temp2 = temp;
            free(temp->next);   // son düğümü serbest bırakma
            temp2->next = NULL; // son düğümün göstericisini NULL yapma
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
        while (temp->next != NULL)
        {
            adet++;
            temp = temp->next; // tüm düğümleri sayma
        }
        adet++;
        return adet;
    }
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
        while (temp->next != NULL)
        {
            printf("%d \n ", temp->data); // tüm düğümleri yazdırma
            temp = temp->next;            // bir sonraki düğüme geçme
        }
        printf("%d\n", temp->data); // son düğümün verisini yazdırma
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
int main()
{
    while (1)
    {
        int secim, sayi;
        printf("\n1--> Basa eleman ekle: \n");
        printf("2--> Sona eleman ekle: \n");
        printf("3--> Bastan eleman sil: \n");
        printf("4--> Sondan eleman sil: \n");
        printf("5--> Eleman sayisini goster: \n");
        printf("6--> Datalarin toplamini goster: \n");
        printf("7--> Listeyi goster: \n");
        printf("8--> Cikis: \n");
        printf("Seciminiz: ");
        scanf("%d", &secim);
        switch (secim)
        {
        case 1:
            printf("Basa eklenecek sayiyi giriniz: ");
            scanf("%d", &sayi);
            basaEkle(sayi);
            break;
        case 2:
            printf("Sona eklenecek sayiyi giriniz: ");
            scanf("%d", &sayi);
            sonaEkle(sayi);
            break;
        case 3:
            bastanSil();
            break;
        case 4:
            sondanSil();
            break;
        case 5:
            printf("Eleman sayisi: %d\n", elemanSay());
            break;
        case 6:
            printf("Data toplami: %d\n", dataToplam());
            break;
        case 7:
            listele();
            break;
        case 8:
            return 0; // program sonu
        }
    }
    return 0;
}