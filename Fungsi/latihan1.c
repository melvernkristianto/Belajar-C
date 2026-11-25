#include <stdio.h>

int hitung_kupon(int kode);

int main(void){
    int kode;
    int poin;

    printf("masukan kode: ");
    scanf("%d", &kode);

    if (kode < 0){
        printf("kode harus positif");
        return 0;
    }

    int total_poin = hitung_kupon(kode);
    printf("total poin kupon %d adalah %d", kode, total_poin);

    return 0;
}

int hitung_kupon(int kode){
    if (kode == 0){
        return 0;
    }

    int digit = kode%10;
    int poin = 0;

    
    if (digit == 0){
        poin = 10;
    } else if (digit % 2 == 0){
        poin = 2;
    } else {
        poin = 1;
    }
    

    return poin + hitung_kupon(kode/10);
}