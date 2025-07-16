#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *temp = NULL;
struct node *top = NULL;
void push(int veri)
{
    struct node *eleman = (struct node *)malloc(sizeof(struct node));
    eleman->data = veri;
    if (top == NULL)
    {
        top = eleman;
        top->next = NULL;
    }
    else
    {
        eleman->next = top;
        top = eleman;
    }
}
void pop()
{
    if (top == NULL)
    {
        printf("Yigin bos.\n");
    }
    else
    {
        printf("%d elemani stack'tan cikartildi.\n", top->data);
        temp = top->next;
        free(top);
        top = temp;
    }
}
void print()
{
    system("cls");
    if (top == NULL)
        printf("stacl bos\n");
    else
    {
        temp = top;
        while (temp->next != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d \n", temp->data);
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
            push(sayi);
            break;
        case 2:
            pop();
            break;
        case 3:
            print();
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