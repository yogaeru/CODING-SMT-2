#include <iostream>

struct Node
{
    int nodeValue;
    Node *next = NULL;
};

struct SingleLinkedList
{
private:
    Node *head, *tail, *newNode;

public:
    SingleLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void add(int data)
    {
        Node *addNode = new Node();
        addNode->nodeValue = data;
        addNode->next = NULL;
        if (head == NULL)
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

    void insertNode(int index, int data)
    {
        Node *insertNode = new Node();
    }

    void print()
    {
        Node *cur = head;
        while (cur != NULL)
        {
            std::cout << cur->nodeValue;
            cur = cur->next;
            if (cur != NULL)
            {
                std::cout << ", ";
            }
        }
        std::cout << '\n';
    }
};

int main()
{
    SingleLinkedList listNilai;
    listNilai.add(900);

    listNilai.print();

    return 0;
}