#include <stdio.h>
#define MAX_BARANG 20

int baca_bilangan_dalam_rentang(int nilai_minimum, int nilai_maksimum, int jumlah_jenis_barang);
double baca_bilangan_positif(double harga_satuan);
double hitung_subtotal(double harga_satuan, int jumlah_unit);
double hitung_total(const double subtotal[], int jumlah_data);
double hitung_persen_diskon(double total_belanja, int status_member);
double hitung_diskon(double nilai_belanja, double persentase_diskon);
double hitung_biaya_layanan(double nilai_setelah_diskon);
double hitung_total_pembayaran(double nilai_setelah_diskon,double biaya_layanan);
void tampilkan_ringkasan(double total_belanja,double persentase_diskon,double nilai_diskon,double biaya_layanan,double total_pembayaran);


int main(void){
    int jumlah_jenis_barang;
    int nomor_barang;
    int jumlah_unit;
    int status_member;
    double harga_satuan;
    double subtotal_barang[MAX_BARANG];
    double total_belanja;
    double persentase_diskon;
    double nilai_diskon;
    double nilai_setelah_diskon;
    double biaya_layanan;
    double total_pembayaran;

    printf(
        "======================================\n"
        "         PROGRAM REKAP BELANJA        \n"
        "======================================\n"
        "Masukan Jumlah jenis Barang (1-20): "
    );   
    scanf("%d", &jumlah_jenis_barang);

    // jumlah_jenis_barang = baca_bilangan_dalam_rentang(1, MAX_BARANG, jumlah_jenis_barang);
    
    for (nomor_barang = 1; nomor_barang <= jumlah_jenis_barang; nomor_barang++){
        printf("\nBARANG KE-%d\n", nomor_barang);

        printf("Harga satuan    : ");
        scanf("%lf", &harga_satuan);
        harga_satuan = baca_bilangan_positif(harga_satuan);

        printf("\nJumlah unit     : ");
        scanf("%d", &jumlah_unit);

        printf("Subtotal        : %.2lf\n", hitung_subtotal(harga_satuan, jumlah_unit));

    }   
    return 0;
}

int baca_bilangan_dalam_rentang(int nilai_minimum, int nilai_maksimum, int jumlah_jenis_barang){
    if (jumlah_jenis_barang < nilai_minimum || jumlah_jenis_barang > nilai_maksimum){
        return 0;
    }
    return jumlah_jenis_barang;

}
double baca_bilangan_positif(double harga_satuan){
    if (harga_satuan < 0){
        return 0;
    }
    return harga_satuan;
}
double hitung_subtotal(double harga_satuan, int jumlah_unit){
    return harga_satuan * jumlah_unit;
}
// double hitung_total(const double subtotal[], int jumlah_data);
// double hitung_persen_diskon(double total_belanja, int status_member);
// double hitung_diskon(double nilai_belanja, double persentase_diskon);
// double hitung_biaya_layanan(double nilai_setelah_diskon);
// double hitung_total_pembayaran(double nilai_setelah_diskon,double biaya_layanan);
// void tampilkan_ringkasan(double total_belanja,double persentase_diskon,double nilai_diskon,double biaya_layanan,double total_pembayaran);