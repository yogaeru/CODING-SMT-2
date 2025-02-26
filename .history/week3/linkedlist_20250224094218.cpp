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
    }
};

int main()
{

    return 0;
}