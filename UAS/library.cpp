#include <iostream>
using std::string;

struct Pasien {
    string nama, penyakit;
    int umur, nomor, index;

    Pasien(string nama,
           int umur,
           string penyakit,
           int nomor,
           int abjad) : nama(nama), penyakit(penyakit), umur(umur), nomor(nomor), index(abjad) {
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
    database() : head(nullptr), tail(nullptr) {}

    ~database() {
        Node *cur = head;
        while (cur) {
            Node *del = cur;
            cur = cur->next;
            delete del;
        }
    }

    int length() {
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

    Node *begin() {
        return head;
    }

    Node *back() {
        return tail;
    }

    void addPasien(string nama,
                   int umur,
                   string &penyakit,
                   int nomor) {
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
        if (!head) {
            std::cout << "Data masih kosong !!!!!\n";
            return;
        }
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
            if (right->next) { right->next->prev = left;}
            if (left->prev) {left->prev->next = right;}
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
    void urutkan_data(string data = "nomor") {
        if (!head) {
            std::cout << "Data masih kosong !!!!\n";
            return;
        }
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
    }


    
// asasddd
    /*  <================================= ALGORITMA SEARCHING    =====================================> */
    /*  <================================= ALGORITMA SEARCHING    =====================================> */
    /*  <================================= ALGORITMA SEARCHING    =====================================> */
    void cari_str(string type, string target, Node *cur = nullptr, bool found = false) {
        if (!cur)
            cur = head;
        string &value = (type == "nama") ? cur->value->nama : cur->value->penyakit;

        if (value == target) {
            // std::cout << "<==== DATA  DITEMUKAN!!! ===>\n";
            std::cout << "\n";
            std::cout << "Nama Pasien : " << cur->value->nama << '\n';
            std::cout << "Umur Pasien : " << cur->value->umur << '\n';
            std::cout << "Penyakit Pasien : " << cur->value->penyakit << '\n';
            std::cout << "Nomor Pasien : " << cur->value->nomor << '\n';
            // std::cout << "====================================\n\n";
            std::cout << "\n";
            found = true;
        }

        if (cur->next) {
            //rekursif
            cari_str(type, target, cur->next, found);
        } else if (!found) {
            std::cout << "Data Pasien Tidak Ditemukan!!!\n";
        }
    }

    void cari_num(string type, int value) {
        Node *cur = head;
        bool found = false;
        while (cur) {
            int data = (type == "umur") ? cur->value->umur : cur->value->nomor;
            if (data == value) {
                // std::cout << "<=== DATA  DITEMUKAN!!! ===>\n";
                std::cout << "\n";
                std::cout << "Nama Pasien : " << cur->value->nama << '\n';
                std::cout << "Umur Pasien : " << cur->value->umur << '\n';
                std::cout << "Penyakit Pasien : " << cur->value->penyakit << '\n';
                std::cout << "Nomor Pasien : " << cur->value->nomor << '\n';
                // std::cout << "====================================\n";
                std::cout << "\n";
                found = true;
            }
            cur = cur->next;
        }
        if (!found) std::cout << "Data Pasien Tidak Ditemukan!!!\n";
    }


};
