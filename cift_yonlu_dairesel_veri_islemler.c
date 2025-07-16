#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *next = NULL;
struct node *start = NULL;
struct node *temp = NULL;
struct node *prev = NULL;
struct node *temp2 = NULL;
void basaEkle(int sayi)
{
    struct node *eleman = (struct node *)malloc(sizeof(struct node));
    eleman->data = sayi;
    if (start == NULL)
    {
        start = eleman;
        start->next = start;
        start->prev = start;
    }
    else
    {
        if (start->next == start)
        {
            start->next = eleman;
            start->prev = eleman;
            eleman->prev = start;
            start = eleman;
        }
        else
        {
            temp = start;
            while (temp->next != start)
            {
                temp = temp->next;
            }
            temp->next = eleman;
            eleman->prev = temp;
            eleman->next = start;
            start->prev = eleman;
            start = eleman;
        }
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
            temp = start;
            while (temp->next != start)
            {
                temp = temp->next;
            }
            temp2 = start->next;
            free(start);
            temp->next = temp2;
            temp2->prev = temp;
            start = temp2;
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
            temp = start;
            while (temp->next != start)
            {
                temp = temp->next;
            }
            temp2 = temp->prev;
            free(temp);
            temp2->next = start;
            start->prev = temp2;
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
            temp = temp->next;
        }
        adet++;
        return adet;
    }
}
void listele()
{
    system("cls");
    if (start == NULL)
    {
        printf("Liste bos.\n");
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
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
            toplam += temp->data;
            temp = temp->next;
        }
        toplam += temp->data;
        return toplam;
    }
}
int main()
{
    int secim, sayi;
    while (1)
    {
        printf("\n1. Basa Ekle\n");
        printf("2. Bastan Sil\n");
        printf("3. Sondan Sil\n");
        printf("4. Eleman Sayisi\n");
        printf("5. Listele\n");
        printf("6. Data Toplam\n");
        printf("7. Cikis\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim)
        {
        case 1:
            printf("Eklenecek sayiyi giriniz: ");
            scanf("%d", &sayi);
            basaEkle(sayi);
            break;
        case 2:
            bastanSil();
            break;
        case 3:
            sondanSil();
            break;
        case 4:
            printf("Eleman sayisi: %d\n", elemanSay());
            break;
        case 5:
            listele();
            break;
        case 6:
            printf("Data toplami: %d\n", dataToplam());
            break;
        case 7:
            exit(0);
        default:
            printf("Gecersiz secim.\n");
        }
    }
    return 0;
}