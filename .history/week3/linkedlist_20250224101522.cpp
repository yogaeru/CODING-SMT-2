#include <iostream>

struct Node
{
    int nodeValue;
    Node *next = NULL;
};

struct SingleLinkedList
{
private:
    Node *head = NULL;
    Node *tail = NULL;

public:
    SingleLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void add(int data)
    {
        Node *temp = new Node();
        temp->nodeValue = data;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
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
    listNilai.add(900);
    listNilai.add(900);

    listNilai.print();

    return 0;
}