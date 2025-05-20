#include <iostream>
using std::string;

struct Pasien {
    string nama, penyakit;
    int umur, nomor, index;

    Pasien(const string &nama,
           const int umur,
           const string &penyakit,
           const int nomor, const int abjad) : nama(nama), penyakit(penyakit), umur(umur), nomor(nomor), index(abjad) {
    }
};

struct Node {
    Node *next = nullptr;
    Node *prev = nullptr;
    Pasien *value = nullptr;
};

class database {
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

    void print() const {
        Node *cur = head;
        while (cur) {
            std::cout << cur->value->nama << ' ';
            std::cout << cur->value->umur << ' ';
            std::cout << cur->value->penyakit << ' ';
            std::cout << cur->value->nomor << '\n';
            cur = cur->next;
        }
    }


    /*  <================================= ALGORITMA SORTING    =====================================> */
    /*  <================================= ALGORITMA SORTING    =====================================> */
    /*  <================================= ALGORITMA SORTING    =====================================> */

    void swapNode(Node *left, Node *right) {
        if (left == right) return;
        if (left == head) { head = right; }
        if (right == tail) { tail = left; }

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
            if (right->next) { right->next->prev = left; }
            if (left->prev) { left->prev->next = right; }
            if (tempLeftNext) { tempLeftNext->prev = right; }
            if (tempRightPrev) { tempRightPrev->next = left; }

            // menukar Node saat ini
            right->prev = left->prev;
            left->next = right->next;
            right->next = tempLeftNext;
            left->prev = tempRightPrev;
        }

        if (right == head) { right->prev = nullptr; }
        if (left == tail) { left->next = nullptr; }
    }

    //SELECTION SORT
    void urutkan_data(const string &data = "nomor") {
        int len = this->length(); //menentukan panjang Node

        Node *left = head;
        Node *right = nullptr;
        Node *minimum = nullptr;
        Node *temp = nullptr;
        int minVal, rightVal;

        for (int step = 0; step < len; step++) {
            minimum = left;
            right = minimum->next;

            //menentukan data yang akan di sorting

            while (right) {
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
                if (minVal > rightVal) {
                    minimum = right;
                }
                right = right->next;
            }

            temp = left->next;
            if (minimum != left) {
                this->swapNode(left, minimum);
            }
            left = temp;
        }
        std::cout << "Data Pasien Sudah Diurutkan!!!\n";
    }

    /*  <================================= ALGORITMA SEARCHING    =====================================> */
    /*  <================================= ALGORITMA SEARCHING    =====================================> */
    /*  <================================= ALGORITMA SEARCHING    =====================================> */

    void cari_nama(const string &type, const string &data) {
        int i;
        Node *cur = head;
        while (cur) {
            string &value = (type == "nama") ? cur->value->nama : cur->value->penyakit;
            if (value == data) {
                std::cout << "<=== DATA  DITEMUKAN!!! ===>\n";
                std::cout << "Nama Pasien : " << cur->value->nama << '\n';
                std::cout << "Umur Pasien : " << cur->value->umur << '\n';
                std::cout << "Penyakit Pasien : " << cur->value->penyakit << '\n';
                std::cout << "Nomor Pasien : " << cur->value->nomor << '\n';
                std::cout << "====================================\n";
                return;
            }
            cur = cur->next;
        }
        std::cout << "Data Pasien Tidak Ditemukan!!!\n";
    }

    void cari_data(const string &type, const int value) {
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
                return;
            }
            cur = cur->next;
        }
        std::cout << "Data Pasien Tidak Ditemukan!!!\n";
    }
};
