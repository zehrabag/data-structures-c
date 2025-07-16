#include <stdio.h>
#include <stdlib.h>
// veri girişi
struct dugum // yapı oluşturma
{
    int veri;
    struct dugum *gosterici;
};
int main()
{
    struct dugum *bir;                                  // düğüm oluşturma
    bir = (struct dugum *)malloc(sizeof(struct dugum)); // bellekte yer ayırma

    struct dugum *iki;                                  // düğüm oluşturma
    iki = (struct dugum *)malloc(sizeof(struct dugum)); // bellekte yer ayırma

    struct dugum *uc;                                  // düğüm oluşturma
    uc = (struct dugum *)malloc(sizeof(struct dugum)); // bellekte

    struct dugum *dort;
    dort = (struct dugum *)malloc(sizeof(struct dugum)); // bellekte yer ayırma

    bir->veri = 11;       // düğümlerimize veri girişi yaptık
    bir->gosterici = iki; // bir sonraki düğümü gösteriyor
    iki->veri = 22;
    iki->gosterici = uc;
    uc->veri = 33;
    uc->gosterici = dort;
    dort->veri = 44;
    dort->gosterici = NULL; // son düğümün göstericisi NULL

    printf("%d-%d-%d-%d\n", bir->veri, iki->veri, uc->veri, dort->veri); // verileri ekrana yazdırma
}