#include <iostream>

using namespace std = io;

int main()
{
    int n;
    std::cin >> n;
    std::string namaMakanan[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> namaMakanan[i];
    }

    for (std::string makanan : namaMakanan)
    {
        std::cout << makanan << ' ';
    }

    return 0;
}