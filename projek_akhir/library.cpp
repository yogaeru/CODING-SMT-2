#include <iostream>
using std::string;

struct Pasien {
    string nama, penyakit;
    int umur, nomor, index;

    Pasien(const string &nama,
           const int umur,
           const string &penyakit,
           const int nomor,
           const int abjad) : nama(nama), penyakit(penyakit), umur(umur), nomor(nomor), index(abjad) {
    }
};

struct Node {
    Node *next = nullptr;
    Node *prev = nullptr;
    Pasien *value = nullptr;
};

struct database {
private:
    Node *head, *tail;
    string abjad = "abcdefghijklmnopqrstuvwxyz";

public:
    database() : head(nullptr), tail(nullptr) {
    }

    ~database() {
        Node *cur = head;
        while (cur) {
            Node *del = cur;
            cur = cur->next;
            delete del;
        }
    }

    int length() const {
        int count = 0;
        Node *cur = head;

        while (cur) {
            count++;
            cur = cur->next;
        }
        return count;
    }

    int getAbjad(char abj) {
        string &data = this->abjad;
        int i;
        for (i = 0; i < 26; i++) {
            if (data[i] == abj) {
                return i;
            }
        }
        return i;
    }

    void addPasien(const string &nama,
                   const int umur,
                   const string &penyakit,
                   const int nomor) {
        Node *pasien = new Node();
        int indexAbj = this->getAbjad(tolower(nama[0]));
        pasien->value = new Pasien(nama, umur, penyakit, nomor, indexAbj);

        if (!head) {
            head = pasien;
            tail = pasien;
        } else {
            pasien->prev = tail;
            tail->next = pasien;
            tail = pasien;
        }
    }

    void print(Node *cur = nullptr) {
        if (!cur) cur = head;
        std::cout << cur->value->nama << ' ';
        std::cout << cur->value->umur << ' ';
        std::cout << cur->value->penyakit << ' ';
        std::cout << cur->value->nomor << '\n';

        // rekursif
        if (cur->next) {
            print(cur->next);
        }
    }

    /*  <================================= ALGORITMA SORTING    =====================================> */
    /*  <================================= ALGORITMA SORTING    =====================================> */
    /*  <================================= ALGORITMA SORTING    =====================================> */

    void swapNode(Node *left, Node *right) {
        if (left == right)
            return;
        if (left == head) {
            head = right;
        }
        if (right == tail) {
            tail = left;
        }

        if (left->next == right) {
            if (right->next) {
                left->next = right->next;
                right->next->prev = left;
            }
            if (left->prev) {
                left->prev->next = right;
                right->prev = left->prev;
            }
            right->next = left;
            left->prev = right;
        } else {
            /***
                Variabel untuk menyimpan Node setelah left
                dan Node sebelum right
             ***/
            Node *tempLeftNext = left->next;
            Node *tempRightPrev = right->prev;

            // Untuk merubah pointer Node sebelumnya dan Node setelahnya
            if (right->next) {
                right->next->prev = left;
            }
            if (left->prev) {
                left->prev->next = right;
            }
            if (tempLeftNext) {
                tempLeftNext->prev = right;
            }
            if (tempRightPrev) {
                tempRightPrev->next = left;
            }

            // menukar Node saat ini
            right->prev = left->prev;
            left->next = right->next;
            right->next = tempLeftNext;
            left->prev = tempRightPrev;
        }

        if (right == head) {
            right->prev = nullptr;
        }
        if (left == tail) {
            left->next = nullptr;
        }
    }

    // <============================ SELECTION SORT ================================>
    // <============================ SELECTION SORT ================================>
    void urutkan_data(const string &data = "nomor") {
        int len = this->length(); // menentukan panjang Node

        Node *left = head;
        Node *right = nullptr;
        Node *minimum = nullptr;
        Node *temp = nullptr;
        int minVal, rightVal;

        for (int step = 0; step < len; step++) {
            minimum = left;
            right = minimum->next;

            while (right) {
                // menentukan data yang akan di sorting
                if (data == "nama") {
                    minVal = minimum->value->index;
                    rightVal = right->value->index;
                } else if (data == "umur") {
                    minVal = minimum->value->umur;
                    rightVal = right->value->umur;
                } else {
                    minVal = minimum->value->nomor;
                    rightVal = right->value->nomor;
                }

                // jika Node kanan lebih kecil minimum pindahkan ke kanan
                if (minVal > rightVal) {
                    minimum = right;
                }
                right = right->next;
            } // end while loop

            temp = left->next;
            if (minimum != left) {
                this->swapNode(left, minimum);
            }
            left = temp;
        } // end for loop
        std::cout << "Data Pasien Sudah Diurutkan!!!\n";
    }

    // <======================= BUBBLE SORT =====================>
    // <======================= BUBBLE SORT =====================>

    void bubble_sort(const string &data = "nomor") {
        int len = this->length(); // menentukan panjang Node
        bool swapped = true;

        while (swapped) {
            swapped = false;
            Node *left = head;
            Node *right = left->next;

            for (int step = 0; step < len - 1; step++) {
                Node *tempLeft = left;
                Node *tempRight = right;

                // cek user ingin cari data bedasarkan apa
                int valueKanan, valueKiri;
                if (data == "nama") {
                    valueKanan = tempRight->value->index;
                    valueKiri = tempLeft->value->index;
                } else if (data == "umur") {
                    valueKanan = tempRight->value->umur;
                    valueKiri = tempLeft->value->umur;
                } else {
                    valueKanan = tempRight->value->nomor;
                    valueKiri = tempLeft->value->nomor;
                }

                // jika value Node kiri lebih besar tukar posisinya
                if (valueKiri > valueKanan) {
                    this->swapNode(tempLeft, tempRight);
                    swapped = true;
                    right = tempLeft->next;
                } else {
                    left = left->next;
                    right = right->next;
                }
            }
            len--;
        }
        std::cout << "data sudah terurut\n";
    }

    // <======================= INSERTION SORT =====================>
    // <======================= INSERTION SORT =====================>
    void insertion_sort(const string &data = "nomor") {
        int len = this->length(); // panjang Node
        Node *right = head->next; // Node kanan atau I
        Node *left = nullptr; // Node kiri atau J

        for (int i = 1; i < len; i++) {
            // value Node kanan
            Node *key = right;
            int keyVal;

            if (data == "nama") {
                keyVal = key->value->index;
            } else if (data == "umur") {
                keyVal = key->value->umur;
            } else {
                keyVal = key->value->nomor;
            }

            right = right->next;
            left = key->prev;

            while (left) {
                int leftVal;

                // MEGAMBIL DATA BERDASARKAN YANG DICARI
                if (data == "nama")
                    leftVal = left->value->index;
                else if (data == "umur")
                    leftVal = left->value->umur;
                else
                    leftVal = left->value->nomor;

                /*
                    MENGECEK APAKAH VALUE NODE KIRI > NODE KEY
                    JIKA TIDAK MAKA BREAK
                */
                if (leftVal > keyVal) {
                    Node *temp = left;
                    left = left->prev;
                    this->swapNode(temp, key);
                } else {
                    break;
                }
            }

            /*
                JIKA LEFT NULL MAKA LEFT = HEAD
                JIKA TIDAK NULL MAKA LEFT = LEFT->NEXT
                LALU KITA SWAP LEFT DAN KEY
             */
            left = (left) ? left->next : head;
            this->swapNode(left, key);
        }
    }

    /*  <================================= ALGORITMA SEARCHING    =====================================> */
    /*  <================================= ALGORITMA SEARCHING    =====================================> */
    /*  <================================= ALGORITMA SEARCHING    =====================================> */

    void cari_nama(string type, string target, Node *cur = nullptr, bool found = false) {
        if (!cur)
            cur = head;
        string &value = (type == "nama") ? cur->value->nama : cur->value->penyakit;

        if (value == target) {
            std::cout << "<==== DATA  DITEMUKAN!!! ===>\n";
            std::cout << "Nama Pasien : " << cur->value->nama << '\n';
            std::cout << "Umur Pasien : " << cur->value->umur << '\n';
            std::cout << "Penyakit Pasien : " << cur->value->penyakit << '\n';
            std::cout << "Nomor Pasien : " << cur->value->nomor << '\n';
            std::cout << "====================================\n";
            found = true;
        }

        if (cur->next) {
            //rekursif
            cari_nama(type, target, cur->next, found);
        } else if (!found) {
            std::cout << "Data Pasien Tidak Ditemukan!!!\n";
        }
    }

    void cari_data(string type, int value) {
        Node *cur = head;
        while (cur) {
            int data = (type == "umur") ? cur->value->umur : cur->value->nomor;
            if (data == value) {
                std::cout << "<=== DATA  DITEMUKAN!!! ===>\n";
                std::cout << "Nama Pasien : " << cur->value->nama << '\n';
                std::cout << "Umur Pasien : " << cur->value->umur << '\n';
                std::cout << "Penyakit Pasien : " << cur->value->penyakit << '\n';
                std::cout << "Nomor Pasien : " << cur->value->nomor << '\n';
                std::cout << "====================================\n";
            }
            cur = cur->next;
        }
        std::cout << "Data Pasien Tidak Ditemukan!!!\n";
    }

    // <==================== BINARY SEARCH =======================>
    // <==================== BINARY SEARCH =======================>
    // <==================== BINARY SEARCH =======================>

    // UNTUK MENDAPATKAN NODE TENGAH
    Node *getMid(Node *&left, Node *&right) {
        // JIKA LEFT = RIGHT ATAU LEFT->NEXT = RIGHT MAKA RETURN LEFT
        if (left == right or left->next == right) {
            return left;
        }

        // ASIGN VARIABEL
        Node *kiri = left;
        Node *kanan = left->next->next;
        Node *temp = right->next; // TEMP UNTUK MENYIMPAN RIGHT NEXT KARENA AKAN KITA JADIKAN NULL
        right->next = nullptr;

        while (kanan) {
            //  loop selama kanan tidak null
            kiri = kiri->next;
            kanan = kanan->next;
            if (kanan) {
                kanan = kanan->next;
            }
        }
        right->next = temp;
        return kiri;
    }

    Node *binary_search_num(string type, int target, Node *low, Node *high) {
        while (low != high or low == high) {
            Node *mid = getMid(low, high); // mendapatkan node tengah
            int midval_num = (type == "umur") ? mid->value->umur : mid->value->nomor;

            if (midval_num == target) {
                return mid;
            } else if (target > midval_num) {
                low = mid->next;
                if (!low) { return nullptr; }
            } else {
                high = mid->prev;
                if (!high) { return nullptr; }
            }
        }
        return nullptr;
    }

    Node *binary_search_str(string type, string target, Node *low, Node *high) {
        while (low != high or low == high) {
            Node *mid = getMid(low, high);
            string midval_str = (type == "nama") ? mid->value->nama : mid->value->penyakit;

            if (midval_str == target) {
                return mid;
            } else if (midval_str < target) {
                low = mid->next;
                if (!head) { return nullptr; }
            } else {
                high = mid->prev;
                if (!head) { return nullptr; }
            }
        }
        return nullptr;
    }

    void startBinarySearchNum(string type, int target) {
        this->urutkan_data(type);
        Node *data = binary_search_num(type, target, head, tail);
        if (data) {
            std::cout << "YEAY DATA KETEMU !!!\n";
            std::cout << "Nama: " << data->value->nama << '\n';
            std::cout << "Umur: " << data->value->umur << '\n';
            std::cout << "Penyakit: " << data->value->penyakit << '\n';
            std::cout << "Nomor: " << data->value->nomor << '\n';
        } else
            std::cout << "YAHHH DATA PASIEN GK ADA :( \n";
    }

    void startBinarySearchStr(string type, string target) {
        this->urutkan_data(type);
        Node *data = binary_search_str(type, target, head, tail);
        if (data) {
            std::cout << "YEAY DATA KETEMU !!!\n";
            std::cout << "Nama: " << data->value->nama << '\n';
            std::cout << "Umur: " << data->value->umur << '\n';
            std::cout << "Penyakit: " << data->value->penyakit << '\n';
            std::cout << "Nomor: " << data->value->nomor << '\n';
        } else
            std::cout << "YAHHH DATA PASIEN GK ADA :( \n";
    }
};
