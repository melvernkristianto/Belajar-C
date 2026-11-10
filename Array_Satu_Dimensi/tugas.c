#include <stdio.h>
#define MAX_DATA 50

// Deklarasi fungsi
void baca_nilai(double nilai[], int jumlah_data);
double hitung_total(const double nilai[],int jumlah_data);
int cari_indeks_tertinggi(const double nilai[],int jumlah_data);
int cari_indeks_terendah(const double nilai[],int jumlah_data);
int hitung_jumlah_lulus(const double nilai[],int jumlah_data);
int hitung_frekuensi(const double nilai[],int jumlah_data,double target);
void tampilkan_posisi(const double nilai[],int jumlah_data,double target);

int main(void) {
    double nilai[MAX_DATA];     //array 1 dimensi untuk menyimpan data nilai mahasiswa
    int jumlah_data;
    double target;

    printf("==================================================\n");
    printf("           PROGRAM REKAP NILAI MAHASISWA          \n");
    printf("==================================================\n");

    do {
        printf("Masukkan jumlah mahasiswa 1-50: ");
        scanf("%d", &jumlah_data);
    } while (jumlah_data < 1 || jumlah_data > MAX_DATA);

    baca_nilai(nilai, jumlah_data);     // Membaca dan memvalidasi setiap nilai

    double total = hitung_total(nilai, jumlah_data);
    double rata_rata = total / jumlah_data;
    int nilai_tertinggi = cari_indeks_tertinggi(nilai, jumlah_data);
    int nilai_terendah = cari_indeks_terendah(nilai, jumlah_data);
    int lulus = hitung_jumlah_lulus(nilai, jumlah_data);

    printf("\nHASIL REKAP\n");
    printf("--------------------------------------------------\n");
    printf("Jumlah mahasiswa : %d\n", jumlah_data);
    printf("Total nilai      : %.2f\n", total);
    printf("Rata-rata        : %.2f\n", rata_rata);
    printf("Nilai tertinggi  : %.2f (mahasiswa ke-%d)\n", nilai[nilai_tertinggi], nilai_tertinggi + 1);
    printf("Nilai terendah   : %.2f (mahasiswa ke-%d)\n", nilai[nilai_terendah], nilai_terendah + 1);
    printf("Jumlah lulus     : %d\n", lulus);

    // Meminta nilai yang dicari
    printf("\nMasukkan nilai yang dicari: ");
    scanf("%lf", &target);

    printf("\nHASIL PENCARIAN\n");
    printf("--------------------------------------------------\n");
    
    int frekuensi = hitung_frekuensi(nilai, jumlah_data, target);

    if (frekuensi > 0) {
        printf("Nilai %.2f ditemukan pada ", target);
        tampilkan_posisi(nilai, jumlah_data, target);
        printf("Jumlah kemunculan : %d\n", frekuensi);
    } else {
        printf("Nilai %.2f tidak ditemukan.\n", target);
        printf("Jumlah kemunculan : 0\n");
    }
    printf("==================================================\n");

    return 0;
}


// fungsi untuk mengisi array dan memvalidasi setiap nilai (0-100) menggunakan do-while
void baca_nilai(double nilai[], int jumlah_data) {
    for (int i = 0; i < jumlah_data; i++) {
        do {
            printf("Nilai mahasiswa ke-%d: ", i + 1);
            scanf("%lf", &nilai[i]);
        } while (nilai[i] < 0 || nilai[i] > 100);
    }
}

// fungsi untuk menghitung total seluruh nilai
double hitung_total(const double nilai[], int jumlah_data) {
    double total = 0;
    for (int i = 0; i < jumlah_data; i++) {
        total += nilai[i];
    }
    return total;
}

// fungsi untuk mencari indeks nilai tertinggi
int cari_indeks_tertinggi(const double nilai[], int jumlah_data) {
    int max_idx = 0;
    for (int i = 1; i < jumlah_data; i++) {
        if (nilai[i] > nilai[max_idx]) {
            max_idx = i;
        }
    }
    return max_idx;
}

// fungsi untuk mencari indeks nilai terendah
int cari_indeks_terendah(const double nilai[], int jumlah_data) {
    int min_idx = 0;
    for (int i = 1; i < jumlah_data; i++) {
        if (nilai[i] < nilai[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

// fungsi untuk menghitung jumlah mahasiswa dengan nilai >= 60
int hitung_jumlah_lulus(const double nilai[], int jumlah_data) {
    int count = 0;
    for (int i = 0; i < jumlah_data; i++) {
        if (nilai[i] >= 60) {
            count++;
        }
    }
    return count;
}

// fungsi untuk menghitung frekuensi kemunculan nilai target
int hitung_frekuensi(const double nilai[], int jumlah_data, double target) {
    int count = 0;
    for (int i = 0; i < jumlah_data; i++) {
        if (nilai[i] == target) {
            count++;
        }
    }
    return count;
}

// fungsi untuk menampilkan seluruh posisi kemunculan target (sequential search)
void tampilkan_posisi(const double nilai[], int jumlah_data, double target) {
    int dicetak = 0;
    for (int i = 0; i < jumlah_data; i++) {
        if (nilai[i] == target) {
            if (dicetak > 0) {
                printf(", ");
            }
            printf("mahasiswa ke-%d", i + 1);
            dicetak++;
        }
    }
    printf("\n");
}