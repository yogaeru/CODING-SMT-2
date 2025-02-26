#include <iostream>

void addmakanan(std::string namaMakanan[], int n);
void rendermakanan(std::string namaMakanan[], int n);

int main()
{
    int n;    
    std::cin >> n;
    std::cin.ignore();
    std::string namaMakanan[n];

    addmakanan(namaMakanan, n);
    rendermakanan(namaMakanan, n);

    return 0;
}

void addmakanan(std::string namaMakanan[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::getline(std::cin, namaMakanan[i]);
    }
    std::cout << "\n";
}
void rendermakanan(std::string namaMakanan[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << namaMakanan[i] << '\n';
    }
}
