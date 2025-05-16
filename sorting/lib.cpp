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

    void insertion_sort(const std::string &data) {
        int len = this->length(); // panjang Node
        Node *right = head->next; //Node kanan atau I
        Node *left = nullptr; //Node kiri atau J


        for (int i = 1; i < len; i++) {
            //value Node kanan
            Node *key = right;
            long long int keyVal = (data == "nim") ? key->value->nim : key->value->nilaiAngka;

            right = right->next;
            left = key->prev;

            while (left) {
                long long int leftVal = (data == "nim") ? left->value->nim : left->value->nilaiAngka;
                if (leftVal > keyVal) {
                    Node *temp = left;
                    left = left->prev;
                    this->swapNode(temp, key);
                } else { break; }
            }
            left = (left) ? left->next : head;
            this->swapNode(left, key);
        }
    }

    void shell_sort(const std::string &data) {
        int len = this->length();
        int gap = len / 2;

        while (gap > 0) {
            for (int i = gap; i < len; i++) {
                int j = i;
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
        }
    }

    [[nodiscard("return index I")]]
    int partition(const int low, const int high, const std::string &data) {
        int len = this->length();
        int i = low - 1;

        Node *pivot = this->nodeAt(high, len);
        Node *nodeI = (i >= 0) ? this->nodeAt(i, len) : nullptr;
        long long int pivotValue = (data == "nim") ? pivot->value->nim : pivot->value->nilaiAngka;

        for (int j = low; j < high; j++) {
            Node *temp = this->nodeAt(j, len);
            long long int tempValue = (data == "nim") ? temp->value->nim : temp->value->nilaiAngka;
            if (tempValue <= pivotValue) {
                i++;
                nodeI = this->nodeAt(i, len);
                this->swapNode(nodeI, temp);
            }
        }
        Node *temp = (nodeI) ? this->nodeAt(i + 1, len) : head;
        this->swapNode(temp, pivot);
        return i + 1;
    }

    void quick_sort(const std::string &data, const int low, const int high) {
        if (low < high) {
            int pi = this->partition(low, high, data);
            quick_sort(data, low, pi - 1);
            quick_sort(data, pi + 1, high);
        }
    }

    void inPlaceMerge(const std::string &data, int start, int mid, int end) {
        const int len = this->length(); // panjang list
        int start2 = mid + 1; //posisi Node kanan
        Node *left = this->nodeAt(start, len); // Node kiri atau start
        Node *right = this->nodeAt( start2, len); //Node kanan atau mid + 1
        Node *midle = this->nodeAt(mid, len); //Node tengah

        while (start <= mid && start2 <= end) {
            Node *nodeStart = left;
            Node *nodeStart2 = right;
            Node *nodeMid = midle;

            long long int startVal = (data == "nim") ? nodeStart->value->nim : nodeStart->value->nilaiAngka;
            long long int start2Val = (data == "nim") ? nodeStart2->value->nim : nodeStart2->value->nilaiAngka;
            long long int midVal = (data == "nim") ? nodeMid->value->nim : nodeMid->value->nilaiAngka;

            if (midVal <= start2Val) {
                std::cout << "data sudah terurut\n";
                return;
            }

            if (startVal <= start2Val) {
                left = left->next;
                start++;
            } else {
                int index = start2;

                while (index != start) {
                    this->swapNode(nodeStart2->prev, nodeStart2);
                    index--;
                }
                start++;
                start2++;
                mid++;
                right = midle->next;
            }
        }
    }

    void merge_sort(const std::string &data, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2; // menentukan posisi tengah

            merge_sort(data, start, mid);
            merge_sort(data, mid + 1, end);
            inPlaceMerge(data, start, mid, end);
        }
    }

    void MergeSort(const std::string &data) {
        int len = this->length();
        merge_sort(data, 0, len - 1);
    }
};
