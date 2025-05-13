#include <iostream>
#include "lib.cpp"

void nambah(linked_list *a);

void mainMenu(linked_list *a);

void statistik(const linked_list *a);

int main() {
    linked_list *data = new linked_list();
    mainMenu(data);

    delete data;
    return 0;
}


void mainMenu(linked_list *a) {
    // std::cout << "Panjang Node : " << leng << '\n';
    std::string temp;
    char choice;
    while (true) {
        std::cout << "PILIH MENU\n";
        std::cout << "1. Tambah data\n";
        std::cout << "2. Lihat data\n";
        std::cout << "3. Statistik data\n";
        std::cout << "4. Cari Mahasiswa\n";
        std::cout << "5. Exit\n";
        std::cout << "6. Shell Sort\n";

        std::cin >> choice;
        // std::cin.ignore();

        switch (choice) {
            case '1':
                char confirm;
                while (true) {
                    nambah(a);
                    std::cout << "Apkaah ingin menambahkan data lagi ? (y/n)\n";
                    std::cin >> confirm;
                    if (tolower(confirm) != 'y') { break; }
                }
                break;
            case '2':
                std::cout << "======= Data mahasiswa  ===== \n";
                a->print();
                std::cout << "Masukan apa saja untuk kembali...";
                std::cin >> temp;
            // system("cls");
                break;
            case '3':
                std::cout << "Statisti mahasisqa\n";
                statistik(a);
                std::cout << "Masukan apa saja untuk kembali...";
                std::cin >> temp;
                break;
            case '4':
                int nim;
                std::cout << "MEncari mahasiswa\n";
                std::cout << "Masukan Nim: ";
                std::cin >> nim;
                a->cari(nim);
                break;
            case '5':
                std::cout << "Keluar......\n";
                return;
            case '6':
                break;
            case '7':
                a->bubble_sort("nilai");
                break;
            case '8':
                a->selection_sort("nilai");
                break;
            case '9':
                a->shell_sort("nilai");
                break;
            case '0': {
                int leng = a->length() - 1;
                a->quick_sort("nilai", 0, leng);
                break;
            }
            case 'a':
                a->insertion_sort("nilai");
                break;
            case 'b':
                a->MergeSort("nilai");
                break;
        default:
            std::cout << "Pilihan tidak ada!!!!!!!\n";
                break;
        }
    }
}

void nambah(linked_list *a) {
    std::string nama, gender;
    long long int nim;
    std::string huruf;
    int angka;

    std::cout << "Nama: ";
    std::cin >> nama;
    std::cout << "NIM: ";
    std::cin >> nim;
    std::cin.ignore();
    std::cout << "Gender: ";
    std::cin >> gender;
    std::cout << "Nilai: ";
    std::cin >> angka;
    std::cin.ignore();

    if (angka >= 86) {
        huruf = "A";
    } else if (angka < 86 && angka >= 81) {
        huruf = "AB";
    } else if (angka < 81 && angka >= 70) {
        huruf = "B";
    } else if (angka < 70 && angka >= 65) {
        huruf = "BC";
    } else if (angka < 65 && angka >= 60) {
        huruf = "C";
    } else if (angka < 60 && angka >= 50) {
        huruf = "D";
    } else {
        huruf = "E";
    }

    a->addMahasiswa(nama, nim, gender, huruf, angka);
    std::cout << "data berhasil ditambah\n";
}

void statistik(const linked_list *a) {
    const int nilai_rendah = a->nilaiRendah();
    const int nilai_tinggi = a->nilaiTinggi();
    const float mean = a->mean();
    const int jumlahData = a->length();

    std::cout << "Jumlah data mahasiswa = " << jumlahData << '\n';
    std::cout << "Rata rata nilai mahasiswa = " << mean << '\n';
    std::cout << "Nilai mahasiswa teredah = " << nilai_rendah << '\n';
    std::cout << "Nilai mahasiswa tertinggi = " << nilai_tinggi << '\n';
}
