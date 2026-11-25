#include <stdio.h>

// Fungsi tukar nilai menggunakan pointer
void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Satu fungsi mengembalikan banyak hasil (min dan max) lewat parameter pointer
void cariMinMax(int arr[], int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

// Balik array di tempat (in-place) tanpa array tambahan
void balikArray(int arr[], int n) {
    int kiri = 0;
    int kanan = n - 1;

    while (kiri < kanan) {
        tukar(&arr[kiri], &arr[kanan]);
        kiri++;
        kanan--;
    }
}

int main() {
    int suhu[] = {28, 30, 27, 32, 29, 26};
    int n = 6;
    int suhuMin, suhuMax;

    // Pass by reference menggunakan operator &
    cariMinMax(suhu, n, &suhuMin, &suhuMax);

    printf("Data Suhu Awal   : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", suhu[i]);
    }
    printf("\nSuhu Minimum     : %d C\n", suhuMin);
    printf("Suhu Maksimum    : %d C\n", suhuMax);

    // Membalik urutan array
    balikArray(suhu, n);

    printf("Data Suhu Dibalik: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", suhu[i]);
    }
    printf("\n");

    return 0;
}