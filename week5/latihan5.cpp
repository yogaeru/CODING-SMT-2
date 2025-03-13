#include <iostream>

struct Mahasiswa
{
    char code;
    std::string nama;
    long long int nim;
};

struct Node
{
    Mahasiswa *value;
    Node *next = nullptr;
    Node *prev = nullptr;
};

struct linkedList
{
private:
    Node *head, *tail;

public:
    linkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // void push(char code, std::string nama, long long int nim){
    //     Node *mhs = new Node();
    //     mhs->value = {code, nama, nim};

    //     if(!head){
    //         head = mhs;
    //         tail = mhs;
    //     }
    //     else{
    //         mhs->prev = tail;
    //         tail->next = mhs;
    //         tail = mhs;
    //     }
    // }


    void push(char code, std::string nama, long long int nim)
    {
        Node *mhs = new Node();
        mhs->value = new Mahasiswa({code, nama, nim});

        if (!head)
        {
            head = mhs;
            tail = mhs;
        }
        else
        {
            mhs->prev = tail;
            tail->next = mhs;
            tail = mhs;
        }
    }

    void print()
    {
        Node *cur = tail;
        while (cur)
        {
            std::cout << "+------------------------+\n";
            std::cout << "Mahasiswa " << cur->value->code << '\n';
            std::cout << "Nama : " << cur->value->nama << '\n';
            std::cout << "NIM : " << cur->value->nim << "\n";
            std::cout << "+------------------------+\n\n";
            cur = cur->prev;
        }
    }

    void printNim()
    {
        Node *cur = head;
        while (cur)
        {
            std::cout << cur->value->nim << '\n';
            cur = cur->next;
        }
    }

    void printNama()
    {
        Node *cur = tail;
        while (cur)
        {
            std::cout << cur->value->nama << '\n';
            cur = cur->prev;
        }
    }

    void pop()
    {
        if (!head)
            return;

        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            std::cout << "Stack telah kosong";
            return;
        }

        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;

        Node *cur = tail;
        while (cur)
        {
            std::cout << cur->value->nim << '\n';
            cur = cur->prev;
        }
        std::cout << '\n';
    }

    ~linkedList()
    {
        Node *cur = head;
        while (cur)
        {
            Node *next = cur->next;
            delete cur->value; 
            delete cur; 
            cur = next;
        }
    }
};

int main()
{
    linkedList a;
    a.push('A', "Yoga Adhi Prasetiyo", 24100);
    a.push('B', "Nia", 24101);
    a.push('C', "Nemo", 24102);
    a.push('D', "Balmon", 24103);
    a.print();
    a.printNama();
    std::cout << '\n';
    a.printNim();
    std::cout << '\n';
    a.pop();
    a.pop();
    a.pop();
    a.pop();

    return 0;
}