#include <iostream>
#include <string>

struct Mahasiswa {
    std::string nama;
    int long long nim;
    std::string gender;
    std::string nilaiHuruf;
    int nilaiAngka;
};

struct Node {
    Node *next = nullptr;
    Node *prev = nullptr;
    Mahasiswa *value{};
};

struct linked_list {
private:
    Node *head, *tail;

public:
    linked_list() {
        head = nullptr;
        tail = nullptr;
    }

    [[nodiscard]] int length() const {
        const Node *cur = head;
        int leng = 0;

        while (cur) {
            cur = cur->next;
            leng++;
        }

        return leng;
    }

    [[nodiscard]] float mean() const {
        const Node *cur = head;
        int total = 0;
        int leng = 0;

        while (cur) {
            total += cur->value->nilaiAngka;
            leng++;
            cur = cur->next;
        }

        const float mean = static_cast<float>(total) / static_cast<float>(leng);
        return mean;
    }

    void addMahasiswa(const std::string &nama,
                      const long long int nim,
                      const std::string &gender,
                      const std::string &huruf,
                      const int angka) {
        Node *mhs = new Node();
        mhs->value = new Mahasiswa({nama, nim, gender, huruf, angka});

        if (!head) {
            head = mhs;
            tail = mhs;
        } else {
            mhs->prev = tail;
            tail->next = mhs;
            tail = mhs;
        }
    }

    void cari(const long long int nim) const {
        const Node *cur = head;
        bool found = false;
        while (cur) {
            if (cur->value->nim == nim) {
                found = true;
                break;
            }
            cur = cur->next;
        }

        if (found) {
            std::cout << "data ditemukan\n";
            std::cout << "Nama: " << cur->value->nama << "\n";
            std::cout << "NIM: " << cur->value->nim << '\n';
            std::cout << "Gender: " << cur->value->gender << '\n';
            std::cout << "Nilai Angka " << cur->value->nilaiAngka << '\n';
            std::cout << "Nilai huruf " << cur->value->nilaiHuruf << '\n';
        } else {
            std::cout << "data tidak ada\n";
        }
    }

    [[nodiscard]] int nilaiTinggi() const {
        const Node *cur = head;
        int nilai = 0;

        while (cur) {
            if (cur == head) {
                nilai = cur->value->nilaiAngka;
                cur = cur->next;
            } else {
                if (cur->value->nilaiAngka > nilai) {
                    nilai = cur->value->nilaiAngka;
                }
                cur = cur->next;
            }
        }

        return nilai;
    }

    [[nodiscard]] int nilaiRendah() const {
        const Node *cur = head;
        int nilai = 0;

        while (cur) {
            if (cur == head) {
                nilai = cur->value->nilaiAngka;
                cur = cur->next;
            } else {
                if (cur->value->nilaiAngka < nilai) {
                    nilai = cur->value->nilaiAngka;
                }
                cur = cur->next;
            }
        }

        return nilai;
    }

    void print() const {
        const Node *cur = head;
        while (cur) {
            std::cout << "Nama: " << cur->value->nama << "\n";
            std::cout << "NIM: " << cur->value->nim << '\n';
            std::cout << "Gender: " << cur->value->gender << '\n';
            std::cout << "Nilai Angka " << cur->value->nilaiAngka << '\n';
            std::cout << "Nilai huruf " << cur->value->nilaiHuruf << '\n';
            cur = cur->next;
        }
    }
};


void nambah();

void statistik();

void mainMenu();

linked_list a;

int main() {
    mainMenu();

    return 0;
}

void mainMenu() {
    std::string temp;
    char choice;
    while (true) {
        std::cout << "PILIH MENU\n";
        std::cout << "1. Tambah data\n";
        std::cout << "2. Lihat data\n";
        std::cout << "3. Statistik data\n";
        std::cout << "4. Cari Mahasiswa\n";
        std::cout << "5. Exit\n";

        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case '1':
                char confirm;
                while (true) {
                    nambah();
                    std::cout << "Apkaah ingin menambahkan data lagi ? (y/n)\n";
                    std::cin >> confirm;

                    if (confirm == 'n' || confirm == 'N') {
                        break;
                    }
                }

                break;
            case '2':
                std::cout << "======= Data mahasiswa  ===== \n";
                a.print();
                std::cout << "Masukan apa saja untuk kembali...";
                std::cin >> temp;
                break;
            case '3':
                std::cout << "Statisti mahasisqa\n";
                statistik();
                std::cout << "Masukan apa saja untuk kembali...";
                std::cin >> temp;
                break;
            case '4':
                int nim;
                std::cout << "MEncari mahasiswa\n";
                std::cout << "Masukan Nim: ";
                std::cin >> nim;
                a.cari(nim);
                break;
            case '5':
                std::cout << "Keluar......\n";
                return;
            default:
                std::cout << "Pilihan tidak ada!!!!!!!\n";
                break;
        }
    }
}

void nambah() {
    // linked_list a;
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

    a.addMahasiswa(nama, nim, gender, huruf, angka);
    std::cout << "data berhasil ditambah\n";
}

void statistik() {
    const int nilai_rendah = a.nilaiRendah();
    const int nilai_tinggi = a.nilaiTinggi();
    const float mean = a.mean();
    const int jumlahData = a.length();

    std::cout << "Jumlah data mahasiswa = " << jumlahData << '\n';
    std::cout << "Rata rata nilai mahasiswa = " << mean << '\n';
    std::cout << "Nilai mahasiswa teredah = " << nilai_rendah << '\n';
    std::cout << "Nilai mahasiswa tertinggi = " << nilai_tinggi << '\n';
}
