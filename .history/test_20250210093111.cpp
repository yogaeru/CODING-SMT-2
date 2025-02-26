#include <iostream>
namespace io = std;

int main()
{
    int n;
    io::cin >> n;
    io::cin.ignore();
    io::string namaMakanan[n];

    for (int i = 0; i < n; i++)
    {
        io::getline(io::cin, namaMakanan[i]);
    }

    io::cout << "\n";
    
    for (std::string makanan : namaMakanan)
    {
        io::cout << makanan << '\n';
    }

    return 0;
}