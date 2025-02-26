#include <iostream>

struct Mahasiswa
{
    std::string nama;
    long int nim;
};

int main()
{
    // int a = 5;
    // int *ptr = &a;
    // int **ptr2 = &ptr;

    // std::cout << "Nilai a " << a << '\n';
    // std::cout << "alamat a " << &a << '\n';
    // std::cout << "Nilai ptr " << &ptr << '\n';
    // std::cout << "Nilai ptr2 " << ptr2<<'\n';
    int N;
    std::cout << "Ukuran Array: " << '\n';
    std::cin >> N;

    Mahasiswa *mhs1 = new Mahasiswa();
    Mahasiswa *mhs2 = new Mahasiswa[N];

    for (int i = 0; i < N; i++)
    {
        std::cout << "Masukkan nama mhs: ";
        std::getline(std::cin, mhs2[i].nama);

        std::cout << "Masukkan umur mhs: ";
        std::cin >> mhs2[i].nim;
    }

    for(int i=0;i<N;i++){
        std::cout << "Nama Mahasiswa ke-" << i+1 << " : " << mhs2[i].nama;
        std::cout << "Umur Mahasiswa ke-" << i+1 << " : " << mhs2[i].nama;
    }

    std::cout << mhs1 << '\n';
    std::cout << mhs2;

    return 0;
}