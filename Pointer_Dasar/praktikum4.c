#include <stdio.h>
// DEKLARASI FUNGSI
void tampilkan_data(const int *data,int jumlah_data);
int hitung_total(const int *data,int jumlah_data);
void kalikan_semua(int *data,int jumlah_data,int pengali);

//fungsi utama
int main(void){
    int data[] = {1, 2, 3, 4, 5};
    int jumlah_data = (int)(sizeof(data) / sizeof(data[0])); 
    //menghitung jumlah elemen array dengan membagi ukuran total array dengan ukuran satu elemen array
    printf("Data awal : ");
    tampilkan_data(data, jumlah_data); //menampilkan seluruh data awal
    printf("Total : %d\n", hitung_total(data, jumlah_data));
    kalikan_semua(data, jumlah_data, 10); //mengalikan seluruh data dengan 10
    printf("Data akhir : ");
    tampilkan_data(data, jumlah_data); //menampilkan data setelah di kali 10
    return 0;
}

//INISIALISASI FUNGSI
//fungsi untuk menampilkan seluruh data
void tampilkan_data(const int *data,int jumlah_data){
    const int *pointer; // mendeklarasikan variabel pointer bantu untuk menelusuri elemen array satu per satu.
    if ((data == NULL) || (jumlah_data <= 0)){
        printf("Tidak ada data.\n");
        return;
    }
    for (pointer = data; pointer < data + jumlah_data; pointer++){ 
        //untuk menelusuri seluruh elemen array dari awal hingga akhir
        printf("%d ", *pointer);
    }
    printf("\n");
}

//fungsi untuk menghitung total seluruh data
int hitung_total(const int *data,int jumlah_data){
    int total = 0; // mendeklarasikan dan menginialisasi nilai awal variabel total
    const int *pointer; // mendeklarasikan variabel pointer bantu untuk menelusuri elemen array satu per satu.
    if ((data == NULL) || (jumlah_data <= 0)){
        return 0;
    }
    for (pointer = data; pointer < data + jumlah_data; pointer++){
        //untuk menelusuri seluruh elemen array dari awal hingga akhir
        total += *pointer; //menjumlahkan seluruh elemen array menggunakan pointer
    }
    return total; //mengembalikan nilai total
}

//fungsi untuk mengalikan seluruh data dengan pengali
void kalikan_semua(int *data,int jumlah_data,int pengali){
    int *pointer; // mendeklarasikan variabel pointer bantu untuk menelusuri elemen array satu per satu.
    if ((data == NULL) || (jumlah_data <= 0)){
        return;
    }
    for (pointer = data; pointer < data + jumlah_data; pointer++){
        //untuk menelusuri seluruh elemen array dari awal hingga akhir
        *pointer *= pengali; //mengalikan seluruh elemen array dengan pengali menggunakan pointer
    }
}