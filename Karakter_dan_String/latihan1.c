#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char peserta[20][50]; // Array 2D char untuk 20 nama, maks 49 karakter

    // Validasi input diulang sampai benar
    do {
        printf("Masukkan jumlah peserta (1-20): ");
        scanf("%d", &n);
        if (n < 1 || n > 20) {
            printf("Input tidak valid! Masukkan angka antara 1 sampai 20.\n");
        }
    } while (n < 1 || n > 20);

    // Hati-hati sisa newline di buffer setelah scanf()
    getchar();

    int totalKarakter = 0;
    int jumlahHurufA = 0;

    for (int i = 0; i < n; i++) {
        printf("Nama lengkap peserta ke-%d: ", i + 1);
        fgets(peserta[i], sizeof(peserta[i]), stdin);

        // Buang newline ('\n') bawaan fgets()
        peserta[i][strcspn(peserta[i], "\n")] = '\0';

        // Akumulasi panjang nama
        int panjang = strlen(peserta[i]);
        totalKarakter += panjang;

        // Hitung huruf 'A' kapital saja (case-sensitive)
        for (int j = 0; j < panjang; j++) {
            if (peserta[i][j] == 'A') {
                jumlahHurufA++;
            }
        }
    }

    // Type casting ke float agar pembagian tidak dibulatkan ke bawah (integer division)
    float rataPanjang = (float)totalKarakter / n;

    printf("\n--- Statistik Peserta ---\n");
    printf("Rata-rata panjang nama : %.2f karakter\n", rataPanjang);
    printf("Jumlah kemunculan 'A'  : %d kali\n", jumlahHurufA);

    // Sequential Search pakai strcmp()
    char cari[50];
    printf("\nMasukkan nama yang dicari: ");
    fgets(cari, sizeof(cari), stdin);
    cari[strcspn(cari, "\n")] = '\0';

    int ditemukan = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(peserta[i], cari) == 0) {
            ditemukan = i;
            break;
        }
    }

    if (ditemukan != -1) {
        printf("Peserta \"%s\" ditemukan pada urutan ke-%d.\n", cari, ditemukan + 1);
    } else {
        printf("Peserta \"%s\" tidak terdaftar.\n", cari);
    }

    return 0;
}