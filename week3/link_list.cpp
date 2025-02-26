#include <iostream>

struct Node
{
    int nodeValue;
    Node *next = nullptr;
};

struct singleLinkList
{
private:
    Node *head, *tail, *cur, *newNode;

public:
    singleLinkList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void add(int data){
        newNode = new Node();
    }
};

int main()
{

    return 0;
}