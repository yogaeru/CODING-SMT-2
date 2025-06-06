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
    listNilai.insertAt(2, 10);

    listNilai.print();

    return 0;
}
