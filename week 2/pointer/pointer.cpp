#include <iostream>

struct Mahasiswa
{
    std::string nama;
    long long int nim;
};

int main()
{
    // int a = 5;
    // int *ptr = &a;
    // int **ptr2 = &ptr;

    // std::cout << "Nilai a " << a << '\n';
    // std::cout << "alamat a " << &a << '\n';
    // std::cout << "Nilai ptr " << &ptr << '\n';
    // std::cout << "Nilai ptr2 " << **ptr2<<'\n';
    int N;
    std::cout << "Ukuran Array: ";
    std::cin >> N;

    Mahasiswa *mhs1 = new Mahasiswa();
    Mahasiswa *mhs2 = new Mahasiswa[N];
    std::cin.ignore();

    for (int i = 0; i < N; i++)
    {
        std::cout << "Masukkan nama mhs: ";
        std::getline(std::cin, mhs2[i].nama);

        std::cout << "Masukkan NIM mhs: ";
        std::cin >> mhs2[i].nim;
        std::cin.ignore();
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << "Nama Mahasiswa ke-" << i + 1 << " : " << mhs2[i].nama << '\n';
        std::cout << "Nim Mahasiswa ke-" << i + 1 << " : " << mhs2[i].nim << '\n';
    }


    std::cout << sizeof(mhs1);
    return 0;
}