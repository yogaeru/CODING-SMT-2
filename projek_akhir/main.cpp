#include <iostream>
#include <string>
#include "library.cpp"
using std::string;


void mainMenu(database *a);

void nambahPasien(database *a);

void menuSorting(database *a);

void menuSearch(database *a);


int main() {
    database *dataPasien = new database();
    mainMenu(dataPasien);
    delete dataPasien;
    return 0;
}

void mainMenu(database *a) {
    while (true) {
        int pilihan;
        std::cout << "<=== MENU DATA PAIEN ===>\n";
        std::cout << "1. Tambah Pasien\n";
        std::cout << "2. Lihat Data Pasien\n";
        std::cout << "3. Urutkan data\n";
        std::cout << "4. Cari Data\n";
        std::cout << "5. FITUR TAMBAHAN\n";
        std::cout << "6. KELUAR\n";
        std::cout << "Masukkan pilihan anda : ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                nambahPasien(a);
                break;
            case 2:
                a->print();
                break;
            case 3:
                std::cout << "BELUNM ADS FITUR!!\n";
                break;
            case 4:
                std::cout << "BELUNM ADS FITUR!!\n";
                break;
            case 5:
                std::cout << "BELUNM ADS FITUR!!\n";
                break;
            case 6:
                std::cout << "DADAHH!!!\n";
                return;
            default:
                std::cout << "Pilihan tidak tersedia\n";
                break;
        }
    }
}

void menuSorting(database *a) {
    int pilihan;
    std::cout << "<== MENU SORTING ==>\n";
    std::cout << "1. Abjad\n";
    std::cout << "2. Nomor pasien\n";
    std::cout << "3. Umur\n";
    std::cout << "4. Kembali\n";
    std::cout << "Masukkan pilihan anda (-1 untuk kembali) : ";
    std::cin >> pilihan;

    switch (pilihan) {
        case 1:
            a->urutkan_data("nama");
            break;
        case 2:
            a->urutkan_data("nomor");
            break ;
        case 3:
            a->urutkan_data("umur");
        case 4:
            return;
        default:
            std::cout << "Pilihan tidak tersedia\n";
            break;
    }
}

void nambahPasien(database *a) {
    string nama, penyakit;
    char temp;
    while (true) {
        int umur, nomor;
        std::cout << "Masukkan nama pasien : ";
        std::cin >> nama;
        std::cout << "Masukkan umur pasien : ";
        std::cin >> umur;
        std::cin.ignore();
        std::cout << "Masukkan penyakit pasien : ";
        std::cin >> penyakit;
        std::cout << "Masukkan nomor pasien : ";
        std::cin >> nomor;
        a->addPasien(nama, umur, penyakit, nomor);
        std::cout << "Data pasien berhasil ditambahkan\n";
        std::cout << "Tambahkan data pasien lagi ? (y/n) : ";
        std::cin >> temp;
        if (tolower(temp) != 'y') { break; }
    }
}
