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
        Node *insertNode = new Node;
        insertNode->nodeValue = data;
        int nodeLength = length();

        if (index == 0)
        {
            addFirst(data);
            return;
        }

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
        int lengthNode = length();
        Node *deleteNode = head;
        if (head == tail)
            tail = nullptr;
        head = head->next;
        delete deleteNode;
        if (tail == nullptr)
            std::cout << "Linked List Kosong!!" << '\n';
    }

    // untuk menghapus elemen terakhir dari linked list
    void delLast()
    {
        Node *deleteLast = tail;
        Node *cur = head;

        if (head == nullptr)
            return;

        while (cur->next != tail)
        {
            cur = cur->next;
        }

        tail = cur;
        cur->next = nullptr;
        delete deleteLast;
    }

    // menghapus elemen dari index tertentu
    void deleteAt(int index)
    {
        Node *deleteNode = nullptr;
        Node *cur = head;
        int nodeLength = length();
        int curIndex = 0;

        // kalau index nya 0, maka hapus headnya
        if (index == 0)
        {
            delFirst();
            return;
        }
        // kalau index = panajgn node
        if (index == nodeLength - 1)
        {
            delLast();
            return;
        }
        // kalau index lebih besar dari panjang node-1
        if (index > nodeLength - 1)
        {
            std::cout << "Index not found!!" << '\n';
            return;
        }

        //
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
    // std::cout << "Temp: " << head->next->next->next->nodeValue << '\n';
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
    listNilai.add(9001);
    listNilai.add(9002);
    listNilai.add(9003);
    // listNilai.addFirst(911);
    // listNilai.insertAt(0, 10);
    // listNilai.deleteAt(2);
    // listNilai.delFirst();
    // listNilai.delLast();
    std::cout << "Panjang dari node adalah = " << listNilai.length() << '\n';

    listNilai.print();

    return 0;
}