#include <stdio.h>
#include <stdlib.h>
// KUYRUK(QUEUE) DİNAMİK BAĞLI LİSTELER İLE UYGULAMA
struct node
{
    int data;
    struct node *next;
};
struct node *temp = NULL;
struct node *front = NULL;
struct node *rear = NULL;
void elemanEkle(int veri)
{
    struct node *eleman = (struct node *)malloc(sizeof(struct node));
    eleman->data = veri;
    if (front == NULL)
    {
        front = eleman;
        front->next = NULL;
        rear = eleman;
        rear->next = NULL;
    }
    else if (front->next == front)
    {
        rear->next = eleman;
        rear = eleman;
        rear->next = NULL;
        front->next = rear;
    }
    else
    {
        rear->next = eleman;
        rear = eleman;
        rear->next = NULL;
    }
}
void elemanCikar()
{
    if (front == NULL)
        printf("Kuyruk bod.\n");
    else
    {
        temp = front->next;
        free(front);
        front = temp;
    }
}
void yazdir()
{
    system("cls");
    if (front == NULL)
        printf("Kuyruk bos.\n");
    else
    {
        temp = front;
        while (temp->next != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
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