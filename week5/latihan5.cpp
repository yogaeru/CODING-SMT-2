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

    // void push(const Mahasiswa &mahasiswa){
    //     Node *mhs = new Node();
    //     mhs->value = mahasiswa;

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

    void push(char code, std::string nama, long long int nim){
        Node *mhs = new Node();
        mhs->value = new Mahasiswa({code, nama, nim});

        if(!head){
            head = mhs;
            tail = mhs;
        }
        else{
            mhs->prev = tail;
            tail->next = mhs;
            tail = mhs;
        }
    }

    void print(){
        Node *cur = tail;
        while(cur){
            std::cout << "Mahasiswa " << cur->value->code << '\n';
            std::cout << "Nama : " << cur->value->nama << '\n';
            std::cout << "NIM : " << cur->value->nim << '\n' << '\n';
            cur = cur->prev;
        }
    }


    ~linkedList(){
        Node *cur = head;
        while (cur){
            Node *next = cur->next;
            delete cur->value; // Hapus Mahasiswa yang dialokasikan dengan new
            delete cur;        // Hapus Node
            cur = next;
        }
    }
};

int main()
{
    linkedList a;
    a.push('A', "yoga", 12123);
    a.push('B', "Balmon", 1222);
    a.print();
    
    return 0;
}