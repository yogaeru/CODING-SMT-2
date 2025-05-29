#include <iostream>
#include <string>
#include "library.cpp"
using std::string;


void mainMenu(database *a);

void nambahPasien(database *a);

void menuSorting(database *a);

void menuSearch(database *a);

void testingCode(database *a);


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
        std::cout << "5. Graph\n";
        std::cout << "6. KELUAR\n";
        std::cout << "Masukkan pilihan anda : ";
        std::cin >> pilihan;
        std::cin.ignore();

        switch (pilihan) {
            case 1:
                nambahPasien(a);
                break;
            case 2:
                a->print();
                break;
            case 3:
                menuSorting(a);
                break;
            case 4:
                menuSearch(a);
                break;
            case 5:
                std::cout << "BELUNM ADS FITUR!!\n";
                break;
            case 6:
                std::cout << "DADAHH!!!\n";
                return;
            case 99:
                testingCode(a);
                break;
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
            a->urutkan_data();
            break ;
        case 3:
            a->urutkan_data("umur");
        case 4:
            return;
        case 5:
            a->bubble_sort("nama");
        default:
            std::cout << "Pilihan tidak tersedia\n";
            break;
    }
}

void nambahPasien(database *a) {
    string nama, penyakit;
    int umur, nomor;
    char temp;
    while (true) {
        std::cout << "Masukkan nama pasien : ";
        // std::cin.ignore();
        std::getline(std::cin, nama);
        std::cout << "Masukkan umur pasien : ";
        std::cin >> umur;
        std::cin.ignore();
        std::cout << "Masukkan penyakit pasien : ";
        std::getline(std::cin, penyakit);
        std::cout << "Masukkan nomor pasien : ";
        std::cin >> nomor;
        std::cin.ignore();

        a->addPasien(nama, umur, penyakit, nomor);
        std::cout << "Data pasien berhasil ditambahkan\n";
        std::cout << "Tambahkan data pasien lagi ? (y/n) : ";
        std::cin >> temp;
        std::cin.ignore();
        if (tolower(temp) != 'y') { break; }
    }
}

void menuSearch(database *a) {
    int pilihan;
    while (true) {
        std::cout << "<== MENU SEARCH ==>\n";
        std::cout << "1. Cari Nama Pasien\n";
        std::cout << "2. Penyakit\n";
        std::cout << "3. Nomor Pasien\n";
        std::cout << "4. Kembali\n";
        std::cout << "Masukkan pilihan anda (-1 untuk kembali) : ";
        std::cin >> pilihan;
        std::cin.ignore();

        switch (pilihan) {
            case 1: {
                std::cout << "Masukkan nama pasien yang ingin dicari : ";
                std::string nama;
                std::cin >> nama;
                a->cari_nama("nama", nama);
                break;
            }
            case 2: {
                std::cout << "Masukkan penyakit yang ingin dicari : ";
                std::string penyakit;
                std::cin >> penyakit;
                a->cari_nama("penyakit", penyakit);
                break;
            }
            case 3: {
                std::cout << "Masukkan nomor pasien yang ingin dicari : ";
                int nomor;
                std::cin >> nomor;
                std::cin.ignore();
                a->cari_data("nomor", nomor);
                break;
            }
            case 4:
                return;
            default:
                std::cout << "Pilihan tidak tersedia\n";
                break;
        }
    }
}

void testingCode(database *a) {
    string nama[] = {"Aru", "Nana", "Ai"};
    int umur[] = {20, 21, 22};
    string penyakit[] = {"Cacar", "Batuk", "Flu"};

    for (int i = 0; i < 3; i++) {
        a->addPasien(nama[i], umur[i], penyakit[i], i + 2);
    }
}
