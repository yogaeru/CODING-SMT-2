#include <iostream>
#include <string>

template <typename T>
struct Node
{
    T value;
    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;
};

struct stackBiner
{
private:
    // Node<int> *top;
    int count = 0;
    int Biner[32];

public:
    // stackBiner()
    // {
    //     top = nullptr;
    // }

    // void push(int num)
    // {
    //     Node<int> *newNode = new Node<int>;
    //     newNode->value = num;

    //     if (isEmpty())
    //     {
    //         top = newNode;
    //         count++;
    //     }
    //     else
    //     {
    //         top->next = newNode;
    //         newNode->prev = top;
    //         top = newNode;
    //         count++;
    //     }
    // }

    // void printd()
    // {
    //     Node<int> *cur = top;
    //     while (cur)
    //     {
    //         std::cout << cur->value << " ";
    //         cur = cur->prev;
    //     }
    // }

    // bool isEmpty()
    // {
    //     return (count == 0);
    // }

    std::string convertBiner(int num)
    {
        while (num > 0)
        {
            Biner[count] = num % 2;
            num /= 2;
            count++;
        }

        std::string result;
        for (int i = count - 1; i >= 0; i--)
        {
            result += std::to_string(Biner[i]);
        }

        return result;
    }

    std::string shiftBiner(std::string biner, int shift)
    {
        int sizeBiner = biner.length();

        for (int i = 0; i < shift; i++)
        {
            char last = biner[sizeBiner - 1];

            for (int j = sizeBiner - 1; j >= 0; j--)
            {
                biner[j] = biner[j - 1];
            }
            biner[0] = last;
        }

        return biner;
    }
};

template <typename T>
struct queue
{
private:
public:
};

int main()
{
    stackBiner a;

    std::string biner =a.convertBiner(25);
    std::string sBiner = a.shiftBiner(biner, 3);

    std::cout << biner << '\n';
    std::cout << sBiner << '\n';
    std::cout << std::stoi(biner, 0, 2) << '\n';
    std::cout << std::stoi(sBiner, 0, 2) << '\n';

    return 0;
}