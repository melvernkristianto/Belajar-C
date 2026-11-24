#include <stdio.h>
#define MAX 10

void analisis_penjualan(int data[][MAX], int baris, int kolom);

int main(void){
    int baris;
    int kolom;
    int penjualan[MAX][MAX];

    printf("Masukkan jumlah cabang (1-10): ");
    scanf("%d", &baris);
    printf("Masukkan jumlah hari (1-10): ");
    scanf("%d", &kolom);


    if (baris < 1 || baris > MAX || kolom < 1 || kolom > MAX) {
        printf("Error: Ukuran tabel tidak valid!\n");
        return 1;
    }

    printf("\nMasukkan data penjualan:\n");
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            printf("Cabang %d, Hari %d: ", i + 1, j + 1);
            scanf("%d", &penjualan[i][j]);
        }
    }

    analisis_penjualan(penjualan,baris,kolom);
    return 0;
}

void analisis_penjualan(int data[][MAX], int baris, int kolom){
    int max_value = data[0][0];

    printf("\nTotal Penjualan per Cabang\n");
    for (int i = 0; i < baris ; i++){
        int total_baris = 0;
        for (int j = 0; j < kolom ; j++) {
            total_baris += data[i][j];
            if (data[i][j] > max_value){
                max_value = data[i][j];
            }
        }
        printf("cabang %d: %d unit\n", i + 1, total_baris);
    }

    printf("\n--- Total Penjualan per Hari ---\n");
    for (int j = 0; j < kolom; j++) {
        int totalKolom = 0;
        for (int i = 0; i < baris; i++) {
            totalKolom += data[i][j];
        }
        printf("Hari ke-%d: %d unit\n", j + 1, totalKolom);
    }

    // 3. Tampilkan nilai terbesar & semua posisi kemunculannya
    printf("\n--- Penjualan Tertinggi ---\n");
    printf("Nilai tertinggi: %d unit\n", max_value);
    printf("Ditemukan pada posisi (Cabang, Hari): ");
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            if (data[i][j] == max_value) {
                printf("(%d, %d) ", i + 1, j + 1);
            }
        }
    }
    printf("\n");
}