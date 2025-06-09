#include <iostream>
#include <vector>
#include "library.cpp"
using std::string;

class graph{
private:
    std::vector<Data> AllData;
public:
    void append(string key, Node value){

    }
};

class Data{
private:
    string key;
    Node Value;
public:
    Data(string key, Node value): key(key), Value(value){}

    
};

struct Node2{
    Node2 *prev = nullptr;
    Node2 *next = nullptr;
    Data *Value = nullptr; 
};

class list{
private:
    Node2 *head, *tail;
public:
    list() : head(nullptr), tail(nullptr){}

    void append(Data *&value){
        Node2 *newNode = new Node2;
        newNode->Value = value;

        if (!head){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode ->prev = tail;
            tail = newNode;
        }
    }
};