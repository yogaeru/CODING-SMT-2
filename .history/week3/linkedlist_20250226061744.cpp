#include <iostream>

struct Node
{
    int nodeValue;
    Node *next = nullptr;
};

struct SingleLinkedList
{
private:
    Node *head, *tail;

public:
    SingleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // fungsi untuk menentukan panjang linked list
    int length()
    {
        int count = 0;
        Node *cur = head;

        // if (head == nullptr) return 0;

        while (cur != nullptr)
        {
            cur = cur->next;
            count++;
        }
        return count;
    }

    // ADD FUNCTION
    void add(int data)
    {
        Node *addNode = new Node();
        addNode->nodeValue = data;
        addNode->next = nullptr;
        
        if (head == nullptr)
        {
            head = addNode;
            tail = addNode;
        }
        else
        {
            tail->next = addNode;
            tail = addNode;
        }
    }

    // menambahkan data ke index pertama atau 0
    void addFirst(int data)
    {
        Node *firstNode = new Node();
        firstNode->nodeValue = data;
        firstNode->next = head;
        head = firstNode;
    }

    // untuk menambahkan data ke index tertentu
    void insertAt(int index, int data)
    {
        Node *insertNode = new Node();
        insertNode->nodeValue = data;
        int nodeLength = length();

        if (index == 0)
        {
            insertNode->next = head;
            head = insertNode;
            return;
        }

        // jika index > panjang linked list akan return
        // if (index > nodeLength)
        // {
        //     std::cout << "Index not found!!" << '\n';
        //     return;
        // }

        // jika index = panjang node atau index lebih besar dari newNode
        //  newNode akan ditambahkan stelah elemen terakhir dari panjang Node
        //  contoh kita punya node 1 2 3 maka panjangnya akan 3 dan kita ingin insert node baru ke index 3
        //  itu masih bisa juga karena index 3 itu adalah index ke 4 karena index dimulai dari 0
        //  tapi jika index > nodeLength itu tidak bisa jadi kita kan selalu menambahkanya stelah elemen terakhir
        if (index == nodeLength || index > nodeLength)
        {
            tail->next = insertNode;
            tail = insertNode;
            return;
        }

        Node *cur = head;
        int curIndex = 0;

        while (curIndex < index - 1)
        {
            cur = cur->next;
            curIndex++;
        }

        insertNode->next = cur->next;
        cur->next = insertNode;
    }

    // DELETE FUNCTION
    void delFirst()
    {
        Node *deleteNode = head;
        head = deleteNode->next;
        delete deleteNode;
        return;
    }

    // untuk menghapus elemen terakhir dari linked list
    void delLast()
    {
        Node *deleteLast = tail;
        Node *cur = head;
        while (cur->next != tail)
        {
            cur = cur->next;
        }
        delete deleteLast;

        tail = cur;
        cur->next = nullptr;
    }

    // menghapus elemen dari index tertentu
    void deleteAt(int index)
    {
        Node *deleteNode = nullptr;
        int nodeLength = length();
        Node *cur = head;
        int curIndex = 0;

        if (index == 0)
        {
            deleteNode = head;
            head = deleteNode->next;
            delete deleteNode;
            return;
        }

        if (index == nodeLength - 1)
        {
            deleteNode = tail;
            while (cur->next != tail)
            {
                cur = cur->next;
            }
            delete deleteNode;

            tail = cur;
            cur->next = nullptr;
            return;
        }

        if (index > nodeLength)
        {
            std::cout << "Index not found!!" << '\n';
            return;
        }

        while (curIndex < index - 1)
        {
            cur = cur->next;
            curIndex++;
        }

        deleteNode = cur->next;
        cur->next = deleteNode->next;
        delete deleteNode;
    }

    // fungsi untuk menampilkan isi dari linked list
    void print()
    {
        Node *cur = head;
        std::cout << '[';
        while (cur != nullptr)
        {
            std::cout << cur->nodeValue;
            cur = cur->next;
            if (cur != nullptr)
            {
                std::cout << ", ";
            }
        }

        std::cout << ']';
        std::cout << '\n';
    }
};

int main()
{
    SingleLinkedList listNilai;
    listNilai.add(900);
    // listNilai.add(9001);
    // listNilai.addFirst(911);
    // listNilai.insertAt(1, 10);
    // listNilai.deleteAt(3);
    // listNilai.delFirst();
    listNilai.delLast();
    std::cout << "Panjang dari node adalah = " << listNilai.length() << '\n';

    listNilai.print();

    return 0;
}