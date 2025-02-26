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

    int length()
    {
        int count = 1;
        Node *cur = head;

        while (cur->next != nullptr)
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

    void addFirst(int data)
    {
        Node *firstNode = new Node();
        firstNode->nodeValue = data;
        firstNode->next = head;
        head = firstNode;
    }

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

        if (index > nodeLength)
        {
            std::cout << "Index not found!!" << '\n';
            return;
        }

        //jika index = panjang node atau index lebih besar dari newNode
        // newNode akan ditambahkan stelah elemen terakhir dari panjang Node
        // contoh kita punya node 1 2 3 maka panjangnya akan 3 dan kita ingin insert node baru ke index 3 
        // itu masih bisa juga karena index 3 itu adalah index ke 4 karena index dimulai dari 0
        // tapi jika index > nodeLength itu tidak bisa jadi kita kan selalu menambahkanya stelah elemen terakhir
        if (index == nodeLength  || index > nodeLength)
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

    void deleteAt(int index)
    {
        Node *deleteNode = nullptr;

        if (index == 0)
        {
            deleteNode = head;
            head = deleteNode->next;
            delete deleteNode;
            return;
        }

        Node *cur = head;
        int curIndex = 0;

        while (curIndex < index - 1)
        {
            cur = cur->next;
            curIndex++;
        }

        deleteNode = cur->next;
        cur->next = deleteNode->next;
        delete deleteNode;
    }

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
    listNilai.add(9001);
    listNilai.addFirst(911);
    listNilai.insertAt(100, 10);
    // listNilai.delFirst();
    // listNilai.delLast();
    // std::cout << listNilai.length();

    listNilai.print();

    return 0;
}