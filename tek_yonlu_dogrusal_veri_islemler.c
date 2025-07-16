#include <stdio.h>
#include <stdlib.h>
// TEK YÖNLÜ DOĞRUSAL BAĞLI LİSTE BAŞA-SONA ELEMAN EKLEME
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
void basaEkle(int veri)
{
    struct node *eleman = (struct node *)malloc(sizeof(struct node)); // yeni düğüm için bellek ayırma
    eleman->data = veri;                                              // düğüme veri atama
    if (start == NULL)
    {
        start = eleman;
        start->next = NULL; // ilk düğüm
    }
    else
    {
        temp = start;
        start = eleman;     // baş düğümü yeni düğüm olarak güncelleme
        start->next = temp; // yeni düğümün göstericisi eski başa
    }
}
void sonaEkle(int veri)
{
    struct node *eleman = (struct node *)malloc(sizeof(struct node)); // yeni düğüm için bellek ayırma
    eleman->data = veri;                                              // düğüme veri atama
    eleman->next = NULL;                                              // son düğümün göstericisi NULL
    if (start == NULL)
    {
        start = eleman; // ilk düğüm
    }
    else
    {
        temp = start; // geçici düğüm başa eşitleniyor
        while (temp->next != NULL)
        {
            temp = temp->next; // son düğüme kadar ilerleme
        }
        temp->next = eleman; // son düğümün göstericisini yeni düğüme yönlendirme
    }
}
void bastanSil()
{
    if (start == NULL)
    {
        printf("Liste zaten bos.\n");
        return; // liste boşsa işlem yapma
    }
    else
    {
        temp = start->next; // baş düğümden sonraki düğümü geçici düğüme atama
        free(start);        // baş düğümü serbest bırakma
        start = temp;       // baş düğümü yeni baş düğüm olarak güncelleme
    }
}
void sondanSil()
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
            start = NULL; // liste boşsa başı NULL yapma
        }
        else
        {
            temp = start;
            while (temp->next->next != NULL)
            {
                temp = temp->next; // son düğüme kadar ilerleme
            }
            prev = temp;
            free(temp->next);  // son düğümü serbest bırakma
            prev->next = NULL; // son düğümün göstericisini NULL yapma
        }
    }
}
int elemanSay()
{
    int adet = 0;
    if (start == NULL)
    {
        return 0;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            adet++;
            temp = temp->next; // tüm düğümleri sayma
        }
        adet++;
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
        while (temp->next != NULL)
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
        start = NULL; // liste boşsa başı NULL yapma
    }
    else
    {
        temp = start; // geçici düğüm başa eşitleniyor
        while (temp->next != NULL)
        {
            printf("%d ", temp->data); // tüm düğümleri yazdırma
            temp = temp->next;         // bir sonraki düğüme geçme
        }
        printf("%d\n", temp->data); // satır sonu ekleme
    }
}
int main()
{
    while (1)
    {
        int secim, sayi;
        printf("\n\n\t MENU\n");
        printf("1. Basa eleman ekle\n");
        printf("2. Sona eleman ekle\n");
        printf("3. Bastan eleman sil\n");
        printf("4. Sondan eleman sil\n");
        printf("5. Eleman sayisini goster\n");
        printf("6. Data toplamini goster\n");
        printf("7. Listeyi goster\n");
        printf("8. Cikis\n");
        printf("Seciminizi yapiniz: \n");
        scanf("%d", &secim);
        switch (secim)
        {
        case 1:
            printf("Basa eklenecek sayiyi giriniz: ");
            scanf("%d", &sayi);
            basaEkle(sayi); // başa eleman ekleme
            break;
        case 2:
            printf("Sona eklenecek sayiyi giriniz: ");
            scanf("%d", &sayi);
            sonaEkle(sayi); // sona eleman ekleme
            break;
        case 3:
            bastanSil(); // baştan eleman silme
            break;
        case 4:
            sondanSil(); // sondan eleman silme
            break;
        case 5:
            printf("Eleman sayisi: %d\n", elemanSay()); // eleman sayısını gösterme
            break;
        case 6:
            printf("Data toplami: %d\n", dataToplam()); // data toplamını gösterme
            break;
        case 7:
            listele(); // listeyi gösterme
            break;
        case 8:
            return 0;
        }
    }
    return 0; // program sonu
}