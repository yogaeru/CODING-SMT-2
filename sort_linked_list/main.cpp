#include <iostream>
#include <chrono>
#include "list.cpp"
using std::string;

void forAdd(list *a, int value);
void mainMenu(list *a);

int main()
{
    for (int i = 0; i < 6; i++)
    {
        string temp;
        list *data = new list();
        forAdd(data, 1000);
        // data->print();

        mainMenu(data);
        std::cout << '\n';
        std::cin >> temp;
        system("cls");
        delete data;
    }
    return 0;
}

void forAdd(list *a, int value)
{
    for (int i = value; i > 0; i--)
    {
        a->append(i);
    }
}

void mainMenu(list *a)
{
    char choice;
    std::cout << "\nMENU SORTING\n";
    std::cout << "1. Bubble sort\n";
    std::cout << "2. Selection sort\n";
    std::cout << "3. Insert sort\n";
    std::cout << "4. Shell sort\n";
    std::cout << "5. Quick sort\n";
    std::cout << "6. Merge sort\n";
    std::cout << "7. Exit\n";
    std::cin >> choice;

    switch (choice)
    {
    case '1':
    {
        auto start = std::chrono::high_resolution_clock::now();
        a->bubble_sort();
        auto end = std::chrono::high_resolution_clock::now();
        // a->print();
        std::chrono::duration<double> duration = end - start;
        std::cout << "\nWaktu eksekusi: " << duration.count() << " detik" << std::endl;
        break;
    }
    case '2':
    {
        auto start = std::chrono::high_resolution_clock::now();
        a->selection_sort();
        auto end = std::chrono::high_resolution_clock::now();
        // a->print();
        std::chrono::duration<double> duration = end - start;
        std::cout << "\nWaktu eksekusi: " << duration.count() << " detik" << std::endl;
        break;
    }
    case '3':
    {
        auto start = std::chrono::high_resolution_clock::now();
        a->insertion_sort();
        auto end = std::chrono::high_resolution_clock::now();
        a->print();
        std::chrono::duration<double> duration = end - start;
        std::cout << "\nWaktu eksekusi: " << duration.count() << " detik" << std::endl;
        break;
    }

    case '4':
    {
        auto start = std::chrono::high_resolution_clock::now();
        a->shell_sort();
        auto end = std::chrono::high_resolution_clock::now();
        a->print();
        std::chrono::duration<double> duration = end - start;
        std::cout << "\nWaktu eksekusi: " << duration.count() << " detik" << std::endl;
        break;
    }
    case '5':
    {
        auto start = std::chrono::high_resolution_clock::now();
        a->quickSort();
        auto end = std::chrono::high_resolution_clock::now();
        a->print();
        std::chrono::duration<double> duration = end - start;
        std::cout << "\nWaktu eksekusi: " << duration.count() << " detik" << std::endl;
        break;
    }
    case '6':
    {
        auto start = std::chrono::high_resolution_clock::now();
        a->MergeSort();
        auto end = std::chrono::high_resolution_clock::now();
        a->print();
        std::chrono::duration<double> duration = end - start;
        std::cout << "\nWaktu eksekusi: " << duration.count() << " detik" << std::endl;
        break;
    }
    default:
        return;
    }
}