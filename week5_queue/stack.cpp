#include <iostream>

struct stack
{
private:
    const int batas = 3;
    std::string data[3];
    int count = 0;

public:
    stack()
    {
        for (int i = 0; i < batas; i++)
        {
            data[i] = "kosong";
        }
    }

    void push(std::string newData)
    {
        if (isFull())
        {
            std::cout << "Stack sudah penuh!" << '\n';
            return;
        }
        else
        {
            data[count] = newData;
            count++;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack masih kosong tidak ada yang bisa dihapus" << '\n';
            return;
        }
        else
        {
            count--;
            data[count] = "kosong";
        }
    }

    bool isEmpty()
    {
        return count == 0 ? true : false;
    }

    bool isFull()
    {
        return count == batas ? true : false;
    }

    void checkTop()
    {
        if (isEmpty())
        {
            std::cout << "Stack masih kosong tidak bisa menampilkan top " << '\n';
            return;
        }
        else
        {
            std::cout << "Top dari stack adalah " << data[count - 1] << '\n';
        }
    }

    void print()
    {
        if (isEmpty())
        {
            std::cout << "Stack masih kosong, tidak ada yang bisa diprint" << '\n';
            return;
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                std::cout << i + 1 << ". " << data[i] << '\n';
            }
        }
    }
};

int main()
{
    stack a;
    a.push("bakso");
    a.push("bakwan");
    a.push("mendoan");

    a.pop();        
    a.print();
    a.checkTop();

    return 0;
}