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

    int length() // untuk menghitung panjang linked list atau total node yang dibuat
    {
        Node<T> *cur = head;
        int count = 0;

        while (cur != nullptr)
        {
            cur = cur->next;
            count++;
        }
        return count;
    }

    void add(T data)
    {
        Node<T> *addNode = new Node<T>;
        addNode->nodeValue = data;
        addNode->next = nullptr;
        if (!head) // jika linked list masih kosong atau belum ada node yang dibuat
        {
            // head dan tail akan menunujuk node yang sama
            head = addNode;
            tail = addNode;
        }
        else
        {
            tail->next = addNode; // karena tail masih menunjuk ke node 1 kita arahkan tail ke node baru
            tail = addNode;       // lalu kita ubah node 2 menjadi tail

            // misal kita punya node 1, head dan tail akan menunjuk alamat dari node 1 tadi
            // jika kita menambahkan node baru kondisi else akan tereksekusi
            // karena tail masih menunjuk node 1 saat kita menulis tail->next = node 2
            // itu sebenarnya node 1->next menunjuk node 2 lalu kita atur ulang node 2 menjadi tail
        }
    }

    void addFirst(T data)
    {
        Node<T> *addFirstNode = new Node<T>;
        addFirstNode->nodeValue = data;
        addFirstNode->next = nullptr;

        if (head == nullptr) // jika linked list masih kosong atau belum ada node yang dibuat
        {
            // head dan tail akan menunujuk node yang sama
            head = addFirstNode;
            tail = addFirstNode;
        }
        else
        {
            addFirstNode->next = head; // kita atur node baru next ke head
            head = addFirstNode;       // lalu kita ubah node baru menjadi head
        }
    };

    void insertAt(int index, T data)
    {
        Node<T> *insertNode = new Node<T>;
        insertNode->nodeValue = data;
        insertNode->next = nullptr;

        Node<T> *cur = head;
        int curIndex = 0;
        int lengthNode = length();

        // jika index == 0 berarti kita menambahkan node di awal atau head
        if (index == 0)
        {
            addFirst(data);
            return;
        }

        // jika index = panjang node atau index lebih besar dari panjang node
        // kita akan menambakan node di akhir atau tail
        if (index == lengthNode - 1 || index > lengthNode)
        {
            add(data);
            return;
        }

        // jika semua kondisi diatas tidka terpenuhi kita akan masuk ke kondisi utama
        while (curIndex < index - 1)
        {
            cur = cur->next;
            curIndex++;
        }
        insertNode->next = cur->next; // insertNode next akan menunjuk cur next
        cur->next = insertNode;       // cur next akan menunjuk insertNode atau node baru yang akan kita sisipkan

        // misal kita punya node 1->2->3->4 lalu ingin menambahkan node 5 di index ke 2 jadi kita
        // harus mendapatkan index-1 atau index sebelummya dulu yaitu node 2 dengan loop
        // cur sekarang akan menunjuk node 2, lalu kita tunjuk 5->next ke 2->next yaitu node 3
        // lalu kita ubah 2->next ke node 5, jadi node akan seperti ini
        // 1->2->5->3->4
    }

    void delFirst()
    {
        if (head == nullptr)
            return;
        Node<T> *delFirstNode = head; // meyimpan alamat head atau node pertama saat ini

        head = head->next;   // kita atur ulang head ke head->next atau ke node setelah head
        delete delFirstNode; // hapus alamat head sebelumnya yang disimpan
    }

    void delLast()
    {
        Node<T> *cur = head;

        while (cur->next != tail)
        {
            cur = cur->next;
        }

        delete tail;          // kita hapus tail karena tail adalah node terakhir
        tail = cur;           // lalu kita atur ulang tail menjadi node sebelumnya
        tail->next = nullptr; // lalu kita atur agar tail next menajdi nullptr yang menjadi tanda akhir node
    }

    void deleteAt(int index)
    {
        Node<T> *del = nullptr;
        Node<T> *cur = head;
        int curIndex = 0;
        int lengthNode = length();

        // jika index lebih besar dari panjang node atau lebih kecil dari 0
        if (index < 0 || index > lengthNode - 1)
        {
            std::cout << "Index not found" << '\n';
            return;
        }
        // jika index adalah node pertama atau head
        if (index == 0)
        {
            delFirst();
            return;
        }
        // jika index adalah noe terakhir atau tail
        if (index == lengthNode - 1)
        {
            delLast();
            return;
        }

        while (curIndex < index - 1)
        {
            cur = cur->next;
            curIndex++;
        }
        del = cur->next;
        cur->next = del->next;
        delete del;
    }

    void print()
    {
        Node<T> *cur = head;
        while (cur != nullptr)
        {
            std::cout << cur->nodeValue << '\n';
            cur = cur->next;
        }
    }
};

int main()
{
    singleLinkList<double> listNilai;
    listNilai.add(500);
    listNilai.add(500.1);
    listNilai.addFirst(80);
    listNilai.addFirst(90);
    listNilai.deleteAt(3);
    listNilai.print();

    std::cout << '\n';
    singleLinkList<std::string> listNama;
    listNama.add("Deden golang");
    listNama.add("Irfan PHP");
    listNama.print();

    return 0;
}