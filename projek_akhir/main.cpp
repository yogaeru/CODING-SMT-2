#include <iostream>
#include <string>
#include "library.cpp"
using std::string;

void mainMenu(database *db);

void nambahPasien(database *db);

void bca(database *db, string type);

void menuSorting(database *db);

void abc(database *db, string type, string target);

void menuSearch(database *db);

void testingCode(database *db);

int main() {
    database *dataPasien = new database();
    mainMenu(dataPasien);
    delete dataPasien;
    return 0;
}

void mainMenu(database *db) {
    string pilihan;
    while (true) {
        std::cout << "\033[2J\033[H";
        std::cout << "=================================\n";
        std::cout << "=========== MAIN MENU ===========\n\n";
        std::cout << "1. Tambah Pasien\n";
        std::cout << "2. Lihat Data Pasien\n";
        std::cout << "3. Urutkan Data Pasien\n";
        std::cout << "4. Cari Data Pasien\n";
        std::cout << "5. GRAPH\n";
        std::cout << "6. Exit\n\n";
        std::cout << "Masukkan pilihan: ";
        std::cin >> pilihan;

        if (pilihan == "1") {
            nambahPasien(db);
        } else if (pilihan == "2") {
            std::cin.ignore();
            db->print();
            std::cout << "Enter Untuk Kembali......";
            std::cin.get();
        } else if (pilihan == "3") {
            menuSorting(db);
        } else if (pilihan == "4") {
            menuSearch(db);
        } else if (pilihan == "5") {
            std::cout << "belum ada FITUR\n";
        } else if (pilihan == "6") {
            return;
        } else if (pilihan == "99") {
            testingCode(db);
        } else {
            std::cout << "YAHHH PILIHAN TIDAK ADA :( \n";
        }
    }
}


// <======== MENAMBAHKAN DATA PASIEN ===========>
// <======== MENAMBAHKAN DATA PASIEN ===========>
// <======== MENAMBAHKAN DATA PASIEN ===========>
// <======== MENAMBAHKAN DATA PASIEN ===========>
// <======== MENAMBAHKAN DATA PASIEN ===========>
void nambahPasien(database *db) {
    string nama, penyakit;
    char validasi;
    int nomor, umur;

    while (true) {
        std::cout << "\033[2J\033[H";
        std::cout << "=================================\n";
        std::cout << "==== MENAMBAHKAN DATA PASIEN ====\n\n";
        std::cout << "Nama pasien : ";
        std::cin.ignore();
        std::getline(std::cin, nama);
        std::cout << "Penyakit    : ";
        std::getline(std::cin, penyakit);
        std::cout << "Umur        : ";
        std::cin >> umur;
        std::cout << "Nomor       : ";
        std::cin >> nomor;
        db->addPasien(nama, umur, penyakit, nomor);

        std::cout << "\nHORE DATA BERHASIL DITAMBAHKAN !!\n";
        std::cout << "Nambah Data Lagi(y/n): ";
        std::cin >> validasi;

        if (tolower(validasi) != 'y')
            break;
    }
}


//====================== MENU SORTING =============================
//====================== MENU SORTING =============================
//====================== MENU SORTING =============================
//====================== MENU SORTING =============================
//====================== MENU SORTING =============================
//====================== MENU SORTING =============================
void menuSorting(database *db) {
    string pilihan;
    string target;
    while (true) {
        std::cout << "\033[2J\033[H\n";
        db->print();
        std::cout << "=====================\n";
        std::cout << "====== SORTING ======\n";
        std::cout << "1. Nama\n";
        std::cout << "2. Umur\n";
        std::cout << "3. Nomor\n";
        std::cout << "4. Kembali\n";

        std::cout << "Masukkan pilihan: ";
        std::cin >> pilihan;

        if (pilihan == "1") {
            bca(db, "nama");
        } else if (pilihan == "2") {
            bca(db, "umur");
        } else if (pilihan == "3") {
            bca(db, "nomor");
        } else if (pilihan == "4") {
            return;
        } else {
            std::cout << "YAHH PILIHAN TIDAK ADAAA :( \n";
        }
    }
}

void bca(database *db, string type) {
    string pilihan;
    while (true) {
        std::cout << "\033[2J\033[H";
        std::cout << "1. Bubble Sort\n";
        std::cout << "2. Selection  Sort\n";
        std::cout << "3. Insertion Sort\n";
        std::cout << "4. Kembali\n";
        std::cout << "Pilihan: ";
        std::cin >> pilihan;

        if (pilihan == "1") {
            db->bubble_sort(type);
            system("pause");
            return;
        } else if (pilihan == "2") {
            db->urutkan_data(type);
            system("pause");
            return;
        } else if (pilihan == "3") {
            db->insertion_sort(type);
            system("pause");
            return;
        } else if (pilihan == "4") {
            return;
        } else {
            std::cout << "YAHH PILIHAN TIDAK ADA :(\n";
        }
    }
}


//====================== MENU SEARCHING ==================================
//====================== MENU SEARCHING ==================================
//====================== MENU SEARCHING ==================================
//====================== MENU SEARCHING ==================================
void menuSearch(database *db) {
    string pilihan, target;

    while (true) {
        std::cout << "\033[2J\033[H";
        std::cout << "1. Nama\n";
        std::cout << "2. Penyakit\n";
        std::cout << "3. Umur\n";
        std::cout << "4. Nomor\n";
        std::cout << "5. Kembali\n";
        std::cout << "Pilihan: \n";
        std::cin >> pilihan;

        if (pilihan == "1") {
            std::cout << "Masukkan nama: ";
            std::cin >> target;
            abc(db, "nama", target);
            system("pause");
        } else if (pilihan == "2") {
            std::cout << "Masukkan penyakit: ";
            std::cin >> target;
            abc(db, "penyakit", target);
            system("pause");
        } else if (pilihan == "3") {
            std::cout << "Masukkan umur: ";
            std::cin >> target;
            abc(db, "umur", target);
            system("pause");
        } else if (pilihan == "4") {
            std::cout << "Masukkan nomor: ";
            std::cin >> target;
            abc(db, "nomor", target);
            system("pause");
        } else if (pilihan == "5") {
            return;
        } else {
            std::cout << "YAHH PILIHAN GK ADA :( \n";
            system("pause");
        }
    }
}

void abc(database *db, string type, string target) {
    string pilihan;
    while (true) {
        std::cout << "\033[2J\033[H";
        std::cout << "1. Linear Search\n";
        std::cout << "2. Bianry Search\n";
        std::cout << "3. Kembali\n";
        std::cout << "Pilih: ";
        std::cin >> pilihan;

        if (pilihan == "1") {
            // linear search
            if (type == "nama" || type == "penyakit") {
                db->cari_nama(type, target);
                return;
            } else {
                db->cari_data(type, std::stoi(target));
                return;
            }
        } else if (pilihan == "2") {
            // binary search
            if (type == "nama" || type == "penyakit") {
                db->startBinarySearchStr(type, target);
                return;
            } else {
                db->startBinarySearchNum(type, std::stoi(target));
                return;
            }
        } else if (pilihan == "3") {
            return;
        } else {
            std::cout << "YAHH PILIHAN TIDAK ADA :(\n";
            std::cin.get();
        }
    }
}


// ====================================== TESTING CODE ===============================
// ===================================== TESTING CODE ===============================
// ====================================== TESTING CODE ===============================
// ======================================== TESTING CODE ===============================
// ======================================== TESTING CODE ===============================
void testingCode(database *db) {
    string nama[] = {"Aru", "Nana", "Ai"};
    int umur[] = {20, 21, 22};
    string penyakit[] = {"Cacar", "Batuk", "Flu"};

    for (int i = 0; i < 3; i++) {
        db->addPasien(nama[i], umur[i], penyakit[i], i + 2);
    }
}

