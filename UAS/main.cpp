#include <iostream>
#include <string>
#include "graph.cpp"
using std::string;

void mainMenu(database *db, Graph *G);
void nambahPasien(database *db, Graph *G);
void menuSorting(database *db);
void menuSearch(database *db);
void testingCode(database *db, Graph *G);

void pause(){
    std::cout << "Enter untuk kembali........";
    std::cin.get();
}

int main() {
    database *dataPasien = new database();
    Graph *G = new Graph();
    mainMenu(dataPasien, G);
    delete dataPasien, G;
    return 0;
}


// =============================== MAIN MENU ===================================
// =============================== MAIN MENU ===================================
// =============================== MAIN MENU ===================================
void mainMenu(database *db, Graph *G) {
    string pilihan;
    bool isempty = db->begin() ? false : true;
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
        std::cin.ignore();

        if (pilihan == "1") {
            nambahPasien(db, G);
            isempty = false;
        } else if (pilihan == "2") {
            std::cout << "\033[2J\033[H";
            db->print();
            std::cout << "Enter Untuk Kembali......";
            std::cin.get();
        } else if (pilihan == "3") {
            if (isempty) {
                std::cout << "Data masih kosong !!!!!\n";
                pause();
            } else {
                menuSorting(db);
            }
        } else if (pilihan == "4") {
            if (isempty) {
                std::cout << "Data masih kosong !!!!!\n";
                pause();
            } else {
                menuSearch(db);
            }
        } else if (pilihan == "5") {
            if (isempty) {
                std::cout << "Data masih kosong !!!!!\n";
                pause();

            } else {
                G->display();
                std::cout << "Enter Untuk Kembali......";
                std::cin.get();
            }
        } else if (pilihan == "6") {
            return;
        } else if (pilihan == "99") {
            testingCode(db, G);
            isempty = false;
        } else {
            std::cout << "YAHHH PILIHAN TIDAK ADA :( \n";
            pause();
        }
    }
}


// <=================================== MENAMBAHKAN DATA PASIEN ============================>
// <=================================== MENAMBAHKAN DATA PASIEN ============================>
// <=================================== MENAMBAHKAN DATA PASIEN ============================>
// <=================================== MENAMBAHKAN DATA PASIEN ============================>
// <=================================== MENAMBAHKAN DATA PASIEN ============================>
void nambahPasien(database *db, Graph *G) {
    string nama, penyakit;
    char validasi;
    int nomor, umur;

    while (true) {
        std::cout << "\033[2J\033[H";
        std::cout << "=================================\n";
        std::cout << "==== MENAMBAHKAN DATA PASIEN ====\n\n";
        std::cout << "Nama pasien : ";
        std::getline(std::cin, nama);
        std::cout << "Penyakit    : ";
        std::getline(std::cin, penyakit);
        std::cout << "Umur        : ";
        std::cin >> umur;
        std::cout << "Nomor       : ";
        std::cin >> nomor;
        db->addPasien(nama, umur, penyakit, nomor);
        G->append(penyakit, db->back());


        std::cout << "\nHORE DATA BERHASIL DITAMBAHKAN !!\n";
        std::cout << "Nambah Data Lagi(y/n): ";
        std::cin >> validasi;
        std::cin.ignore();

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
            db->urutkan_data("nama");
        } else if (pilihan == "2") {
            db->urutkan_data("umur");
        } else if (pilihan == "3") {
            db->urutkan_data();
        } else if (pilihan == "4") {
            return;
        } else {
            std::cout << "YAHH PILIHAN TIDAK ADAAA :( \n";
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
        std::cout << "Pilihan: ";
        std::cin >> pilihan;

        if (pilihan == "1") {
            std::cout << "Masukkan nama: ";
            std::cin >> target;
            std::cin.ignore();
            db->cari_str("nama", target);
            pause();
        } else if (pilihan == "2") {
            std::cout << "Masukkan penyakit: ";
            std::cin >> target;
            std::cin.ignore();
            db->cari_str("penyakit", target);
            pause();
        } else if (pilihan == "3") {
            std::cout << "Masukkan umur: ";
            std::cin >> target;
            std::cin.ignore();
            db->cari_num("umur", std::stoi(target));
            pause();
        } else if (pilihan == "4") {
            std::cout << "Masukkan nomor: ";
            std::cin >> target;
            std::cin.ignore();
            db->cari_num("nomor", std::stoi(target));
            pause();
        } else if (pilihan == "5") {
            return;
        } else {
            std::cout << "YAHH PILIHAN GK ADA :(\n";
            // std::cin.ignore();
            pause();
        }
    }
}

// ====================================== TESTING CODE ===============================
// ===================================== TESTING CODE ===============================
// ====================================== TESTING CODE ===============================
// ======================================== TESTING CODE ===============================
// ======================================== TESTING CODE ===============================
void testingCode(database *db, Graph *G) {
    string nama[] = {"Aru", "Nana", "Ai", "Zara", "Bagus"};
    int umur[] = {20, 21, 22, 19, 17};
    string penyakit[] = {"Cacar", "Batuk", "Flu", "Demam", "Flu"};

    for (int i = 0; i < 5; i++) {
        db->addPasien(nama[i], umur[i], penyakit[i], i + 2);
        G->append(penyakit[i], db->back());
    }
}
