#include  <iostream>
using std::string;

struct Node {
    Node *next = nullptr;
    Node *prev = nullptr;
    int value;
};

class list {
private:
    Node *head, *tail;

public:
    list() : head(nullptr), tail(nullptr) {
    }

    ~list() {
        Node *cur = head;
        while (cur) {
            Node *del = cur;
            cur = cur->next;
            delete del;
        }
    }

    [[nodiscard]] int length() const {
        int count = 0;
        Node *cur = head;
        while (cur) {
            cur = cur->next;
            count++;
        }
        return count;
    }

    void append(int value) {
        Node *addNode = new Node();
        addNode->value = value;

        if (!head) {
            head = addNode;
            tail = addNode;
        } else {
            addNode->prev = tail;
            tail->next = addNode;
            tail = addNode;
        }
    }

    void print() const {
        Node *cur = head;
        std::cout << "[ ";
        while (cur) {
            std::cout << cur->value;
            if (cur->next) std::cout << ", ";
            cur = cur->next;
        }
        std::cout << " ]";
    }


    /***
            ALGORITMA SORTING
     ****/
    [[nodiscard("Return Node at index")]] Node *nodeAt(const int index, const int leng) const {
        Node *cur = head;
        if (index >= leng || index < 0) { return nullptr; }
        for (int i = 0; i < index; i++) {
            if (!cur) { return nullptr; }
            cur = cur->next;
        }
        return cur;
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

    void bubble_sort() {
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
                long long int leftValue = tempLeft->value;
                long long int rightValue = tempRight->value;

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

    void selection_sort() {
        int len = this->length(); //menentukan panjang Node

        Node *left = head;
        Node *right = nullptr;
        Node *minimum = nullptr;
        Node *temp = nullptr;

        for (int step = 0; step < len; step++) {
            minimum = left;
            right = minimum->next;

            while (right) {
                long long int rightValue = right->value;
                long long int minValue = minimum->value;

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


    void insertion_sort() {
        int len = this->length(); // panjang Node
        Node *right = head->next; //Node kanan atau I
        Node *left = nullptr; //Node kiri atau J


        for (int i = 1; i < len; i++) {
            //value Node kanan
            Node *key = right;
            long long int keyVal = key->value;

            right = right->next;
            left = key->prev;

            while (left) {
                long long int leftVal = left->value;
                if (leftVal > keyVal) {
                    Node *temp = left;
                    left = left->prev;
                    this->swapNode(temp, key);
                } else { break; }
            }
            left = (left) ? left->next: head;
            this->swapNode(left, key);
        }
    }

    void shell_sort() {
        int len = this->length();
        int gap = len / 2;

        while (gap > 0) {
            for (int i = gap; i < len; i++) {
                int j = i;
                while (j >= gap) {
                    Node *left = this->nodeAt(j - gap, len);
                    Node *right = this->nodeAt(j, len);

                    long long int tempValue = right->value;
                    long long int leftValue = left->value;

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
    int partition(const int low, const int high) {
        int len = this->length();
        int i = low - 1;

        Node *pivot = this->nodeAt(high, len);
        Node *nodeI = (i >= 0) ? this->nodeAt(i, len) : nullptr;
        long long int pivotValue = pivot->value;

        for (int j = low; j < high; j++) {
            Node *temp = this->nodeAt(j, len);
            long long int tempValue = temp->value;
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

    void quick_sort(const int low, const int high) {
        if (low < high) {
            int pi = this->partition(low, high);
            quick_sort(low, pi - 1);
            quick_sort(pi + 1, high);
        }
    }

    void inPlaceMerge(int start, int mid, int end, int leng) {
        const int len = leng; // panjang list
        int start2 = mid + 1; //posisi Node kanan
        Node *left = this->nodeAt(start, len); // Node kiri atau start
        Node *right = this->nodeAt(start2, len); //Node kanan atau mid + 1
        Node *midle = this->nodeAt(mid, len); //Node tengah

        while (start <= mid && start2 <= end) {
            Node *nodeStart = left;
            Node *nodeStart2 = right;
            Node *nodeMid = midle;

            long long int startVal = nodeStart->value;
            long long int start2Val = nodeStart2->value;
            long long int midVal = nodeMid->value;

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

    void merge_sort(int start, int end, int len) {
        if (start < end) {
            int mid = start + (end - start) / 2; // menentukan posisi tengah
            // int len = this->length();

            merge_sort(start, mid, len);
            merge_sort(mid + 1, end, len);
            inPlaceMerge(start, mid, end, len);
        }
    }

    void quickSort() {
        int len = this->length();
        quick_sort(0, len - 1);
    }

    void MergeSort() {
        int len = this->length();
        merge_sort(0, len - 1, len);
    }
};



