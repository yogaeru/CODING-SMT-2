#include <iostream>
#include <string>

struct Mahasiswa {
    std::string name;
    long long int nim;
    std::string gender;
    std::string nilaiHuruf;
    int nilaiAngka;
};

struct Node {
    Mahasiswa *value = nullptr;
    Node *next = nullptr;
    Node *prev = nullptr;
};

struct linked_list {
private:
    Node *head, *tail;

public:
    linked_list() {
        head = nullptr;
        tail = nullptr;
    }

    ~linked_list() {
        Node *cur = head;
        while (cur) {
            Node *del = cur;
            cur = cur->next;
            delete del;
        }
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
        mhs->value = new Mahasiswa{nama, nim, gender, huruf, angka};
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
            std::cout << "Nama: " << cur->value->name << "\n";
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
                nilai += cur->value->nilaiAngka;
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
            std::cout << cur->value->name << " ";
            std::cout << cur->value->nim << " ";
            std::cout << cur->value->gender << " ";
            std::cout << cur->value->nilaiAngka << " ";
            std::cout << cur->value->nilaiHuruf << "\n";
            cur = cur->next;
        }
        std::cout << "\n";
    }

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

    void bubble_sort(const std::string &data) {
        int len = this->length(); //menentukan panjang Node
        bool swapped = true;

        while (swapped) {
            swapped = false;
            Node *left = head;
            Node *right = left->next;

            for (int step = 0; step < len - 1; step++) {
                Node *tempLeft = left;
                Node *tempRight = right;

                //cek user ingin cari data bedasarkan apa
                long long int leftValue = (data == "nim") ? tempLeft->value->nim : tempLeft->value->nilaiAngka;
                long long int rightValue = (data == "nim") ? tempRight->value->nim : tempRight->value->nilaiAngka;

                //jika value Node kiri lebih besar tukar posisinya
                if (leftValue > rightValue) {
                    this->swapNode(tempLeft, tempRight);
                    swapped = true;
                    right = tempLeft->next;
                } else {
                    left = left->next;
                    right = right->next;
                }
                //kita ubah posisi Node kiri dan kanan
                // left = (swapped) ? tempLeft : tempLeft->next;
                // right = (swapped) ? tempLeft->next : right->next;

                // if (!right) {
                //     std::cout << "data sudah terurut\n";
                //     return;
                // }
            }
            len--;
        }
        std::cout << "data sudah terurut\n";
    }

    void selection_sort(const std::string &data) {
        int len = this->length(); //menentukan panjang Node

        Node *left = head;
        Node *right = nullptr;
        Node *minimum = nullptr;
        Node *temp = nullptr;

        for (int step = 0; step < len; step++) {
            minimum = left;
            right = minimum->next;

            while (right) {
                long long int rightValue = (data == "nim") ? right->value->nim : right->value->nilaiAngka;
                long long int minValue = (data == "nim") ? minimum->value->nim : minimum->value->nilaiAngka;

                if (minValue > rightValue) {
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
        std::cout << "data sudah terurut\n";
    }

    [[nodiscard("Return Node at index")]] Node *nodeAt(const int index, const int leng) const {
        Node *cur = head;
        if (index >= leng || index < 0) { return nullptr; }
        for (int i = 0; i < index; i++) {
            if (!cur) { return nullptr; }
            cur = cur->next;
        }
        return cur;
    }

    void shell_sort(const std::string &data) {
        int len = this->length();
        int gap = len / 2;

        // ciura sequence
        // int gap_container[] = {701, 301, 132, 57, 23, 10, 4, 1};

        // for (int gap: gap_container)
        while (gap > 0) {
            for (int i = gap; i < len; i++) {
                int j = i;
                // Node *temp = nodeAt(i, len);
                while (j >= gap) {
                    Node *left = this->nodeAt(j - gap, len);
                    Node *right = this->nodeAt(j, len);

                    long long int tempValue = (data == "nim") ? right->value->nim : right->value->nilaiAngka;
                    long long int leftValue = (data == "nim") ? left->value->nim : left->value->nilaiAngka;

                    if (leftValue > tempValue) {
                        this->swapNode(left, right);
                        j -= gap;
                    } else { break; }
                }
            }
            gap /= 2;
            // print();
        }
    }

    [[nodiscard("return index I")]]
    int partition(const int low, const int high, const std::string &data) {
        int len = this->length();
        int i = low - 1;

        Node *pivot = nodeAt(high, len);
        Node *nodeI = (i>=0) ? nodeAt(i, len) : nullptr;
        Node *nodeJ = nullptr;

        std::cout << "pivot: " << pivot->value->name << '\n';
        long long int pivotValue = (data == "nim") ? pivot->value->nim : pivot->value->nilaiAngka;

        for (int j = low; j < high; j++) {
            Node *temp = nodeAt(j, len);
            long long int tempValue = (data == "nim") ? temp->value->nim : temp->value->nilaiAngka;
            if (tempValue <= pivotValue) {
                i++;
                nodeI = nodeAt(i, len);
                swapNode(nodeI, temp);
            }
        }
        Node *temp = (nodeI) ? nodeAt(i+1, len) : head;
        swapNode(temp, pivot);
        this->print();
        return i + 1;
    }

    void quick_sort(const std::string &data, const int low, const int high) {
        if (low < high) {
            int pi = partition(low, high, data);
            quick_sort(data, low, pi - 1);
            quick_sort(data, pi + 1, high);
        }
    }
};
