#include <iostream>
#include <utility>

struct Node
{
    std::string value;
    Node *next = nullptr;
    Node *prev = nullptr;
};

struct doubleLL
{
private:
    Node *head, *tail;

public:
    doubleLL()
    {
        head = nullptr;
        tail = nullptr;
    }

    int length()
    {
        Node *cur = head;
        int count = 0;
        while (cur)
        {
            cur = cur->next;
            count++;
        }
        return count;
    }

    void add(const std::string &data)
    {
        Node *addNode = new Node;
        addNode->value = data;

        if (!head)
        {
            head = addNode;
            tail = addNode;
        }
        else
        {
            addNode->prev = tail;
            tail->next = addNode;
            tail = addNode;
        }
    }

    void addFirst(std::string data)
    {
        Node *firstNode = new Node;
        firstNode->value = std::move(data);
        if (!head)
        {
            head = firstNode;
            tail = firstNode;
        }
        else
        {
            firstNode->next = head;
            head->prev = firstNode;
            head = firstNode;
        }
    }

    void insertAt(const int index, std::string data)
    {
        if (!head)
        {
            std::cout << "Belum ada Node tidak bisa Insert!!" << '\n';
            return;
        }
        // jika index 0 maka tambahkan di awal
        if (index == 0)
        {
            addFirst(data);
            return;
        }
        // jika index lebih besar dari pajang linked list node bartu akan ditambahkan sebagai tail
        if (index < 0 || index >= length())
        {
            add(data);
            return;
        }
        // main
        Node *insertNode = new Node;
        insertNode->value = data;

        Node *cur = head;
        int curIndex = 0;

        while (curIndex != index - 1)
        {
            cur = cur->next;
            curIndex++;
        }

        insertNode->next = cur->next;
        insertNode->prev = cur;

        cur->next->prev = insertNode;
        cur->next = insertNode;
    }

    void delFirst()
    {
        if (!head)
        {
            std::cout << "Tidak ada node untuk dihapus!!" << '\n';
            return;
        }

        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }

    void delLast()
    {
        if (!head)
        {
            std::cout << "Tidak ada node untuk dihapus!!" << '\n';
            return;
        }

        if (tail == head)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
            return;
        }

        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }

    void deleteVal(const std::string &data)
    {
        if (!head)
        {
            std::cout << "Tidak ada node untuk dihapus!!" << '\n';
            return;
        }

        Node *del = head;
        while (del)
        {
            if (del->value == data)
            {
                if (del == head)
                {
                    delFirst();
                    return;
                }
                else if (del == tail)
                {
                    delLast();
                    return;
                }
                else
                {
                    del->next->prev = del->prev;
                    del->prev->next = del->next;
                    delete del;
                    return;
                }
            }
            del = del->next;
        }
        std::cout << "Node dengan value " << data << " tidak ditemukan!!" << '\n';
    }

    void print()
    {
        if (!head)
        {
            std::cout << "Tidak ada node!!" << '\n';
            return;
        }

        Node *cur = head;
        while (cur)
        {
            if (cur == head)
            {
                std::cout << "Value Node saat ini: " << cur->value << " dan Node sebelumnya: NULL" << '\n';
                cur = cur->next;
                continue;
            }

            std::cout << "Value Node saat ini: " << cur->value << " dan Node sebelumnya: " << cur->prev->value << '\n';
            cur = cur->next;
        }
    }

    ~doubleLL() {
        Node *cur= head;

        while (cur) {
            delete cur;
            cur = cur->next;
        }
    }
};

int main()
{
    doubleLL a;

    a.add("bakwan");
    a.add("bakso");
    a.add("cendol");
    // a.insertAt(1, "Mendoan");
    a.print();

    std::cout << '\n';

    // a.delFirst();
    // a.delFirst();
    // a.deleteVal("bakso");
    // a.print();

    return 0;
}