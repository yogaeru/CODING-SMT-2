#include <iostream>
#include <vector>
#include "library.cpp"
using std::string;

struct Node2 {
    Node2 *prev = nullptr;
    Node2 *next = nullptr;
    Node *Value = nullptr;
};

class linked_list {
private:
    Node2 *head, *tail;

public:
    linked_list() : head(nullptr), tail(nullptr) {
    }

    void append(Node *value) {
        Node2 *newNode = new Node2();
        newNode->Value = value;

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        Node2 *cur = head;
        while (cur) {
            std::cout << cur->Value->value->nama;
            cur = cur->next;
            if (cur) std::cout << " -> ";
        }
    }
};

struct Data {
    string key;
    linked_list list_of_node; //list of Node

    Data(const string &key): key(key) {
    }
};

struct Graph {
private:
    std::vector<Data> AllData;

public:

    void append(string &key, Node *nodeVal) {
        for (Data &key_val: AllData) {
            if (key_val.key == key) {
                key_val.list_of_node.append(nodeVal);
                return;
            }
        }
        Data newData(key);
        newData.list_of_node.append(nodeVal);
        AllData.push_back(newData);
    }

    void display() {
        for (Data &key_val: AllData) {
            std::cout << "[ " << key_val.key << " ] : ";
            std::cout << "[ ";
            key_val.list_of_node.print();
            std::cout << " ]\n";
        }
    }
};
