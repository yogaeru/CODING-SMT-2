#include <iostream>

struct Mahasiswa
{
    std::string nama;
    long long int nim;
};

int main()
{
    // long long int a;
    // long long int *ptr = &a;

    // std::cin >> a;
    // std::cout << a << '\n';
    // std::cout << &a << '\n';
    // std::cout << ptr << '\n';
    // std::cout << *ptr << '\n';

    // // std::cout << sizeof(a);

    // Mahasiswa *mhs = new Mahasiswa();

    // std::cin >> mhs->nama;
    // std::cin >> mhs->nim;

    // std::cout << mhs->nama << '\n';
    // std::cout << mhs->nim;

    Mahasiswa *mhs = new Mahasiswa[2];

    for (int i = 0; i < 2; i++)
    {
        std::getline(std::cin, mhs[i].nama);
        std::cin >> mhs[i].nim;
        std::cin.ignore();
    }
    
    for (int i = 0; i < 2; i++)
    {
        std::cout << mhs[i].nama;
        std::cout << mhs[i].nim;
    }

    return 0;
}