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

    Mahasiswa *mhs = new Mahasiswa();

    std::cin >> mhs->nama;
    std::cin >> mhs->nim;

    std::cout << mhs->nama << '\n';
    std::cout << mhs->nim;




    return 0;
}