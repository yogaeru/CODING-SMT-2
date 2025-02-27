#include <iostream>

template <typename T>
struct Node
{
    T nodeValue;
    Node<T> *next = nullptr;
};

template <typename T>
struct singleLinkList
{
private:
    Node<T> *head, *tail;

public:
    singleLinkList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void add(T data)
    {
        Node<T> *addNode= new Node();
        addNode->nodeValue = data;
        addNode->next = nullptr;
        if(!=head){
            head = addNode;
            tail = addNode;
        }
        else{
            tail->next = addNode;
            tail = addNode;
        }
    }
};

int main()
{

    return 0;
}