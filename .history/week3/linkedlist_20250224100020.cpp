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
            std::cout << temp->nodeValue << '\n';
        }
        else
        {
            tail->next = temp;
            tail = temp;
            std::cout << temp->nodeValue << '\n';
        }
    }
};

int main()
{
    SingleLinkedList listNilai;
    listNilai.add(900);
    listNilai.add(900);
    listNilai.add(900);


    return 0;
}