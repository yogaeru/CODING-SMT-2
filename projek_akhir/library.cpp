#include <iostream>
using std::string;

struct Pasien {
    string nama, penyakit;
    int umur, nomor;

    Pasien(const string &nama,
           const int umur,
           const string &penyakit,
           const int nomor) : nama(nama), penyakit(penyakit), umur(umur), nomor(nomor) {
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

    void addPasien(const string &nama,
                   const int umur,
                   const string &penyakit,
                   const int nomor) {
        Node *pasien = new Node();
        pasien->value = new Pasien(nama, umur, penyakit, nomor);

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
            if (data == "nama") {
                minVal = minimum->value->nomor;
                rightVal = right->value->nomor;
            } else if (data == "umur") {
                minVal = minimum->value->umur;
                rightVal = right->value->umur;
            } else {
                minVal = minimum->value->nomor;
                rightVal = right->value->nomor;
            }

            while (right) {
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



};
