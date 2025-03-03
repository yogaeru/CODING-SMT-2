#include <iostream>

struct Mahasiswa
{
    std::string nama;
    long long int nim;
    std::string fakultas;
    std::string prodi;
};

void getMhs(Mahasiswa *mhs, int index);
void printMhs(Mahasiswa *mhs, int index);

int main()
{
    int N;
    std::cout << "Masukkan jumlah data mahasiswa: ";
    std::cin >> N;
    std::cin.ignore();

    Mahasiswa *mhs = new Mahasiswa[N];
    getMhs(mhs, N);
    printMhs(mhs, N);

    return 0;
}

void getMhs(Mahasiswa *mhs, int index)
{
    for (int i = 0; i < index; i++)
    {
        std::cout << "Mahasiswa ke " << i + 1 << '\n';
        std::cout << "Nama: ";
        std::getline(std::cin, mhs[i].nama);
        std::cout << "NIM: ";
        std::cin >> mhs[i].nim;
        std::cin.ignore();
        std::cout << "Fakultas: ";
        std::getline(std::cin, mhs[i].fakultas);
        std::cout << "Prodi: ";
        std::getline(std::cin, mhs[i].prodi);
    }
}
void printMhs(Mahasiswa *mhs, int index)
{
    std::cout << "++++++++++++++++++++++++++++++++" << '\n';
    for (int i = 0; i < index; i++)
    {
        std::cout << "Mahasiswa ke " << i + 1 << '\n';
        std::cout << "Nama: " << mhs[i].nama << '\n';
        std::cout << "NIM: " << mhs[i].nim<< '\n';
        std::cout << "Fakultas: " << mhs[i].fakultas << '\n';
        std::cout << "Prodi:" << mhs[i].prodi << '\n';
        std::cout << '\n';
    }
    std::cout << "++++++++++++++++++++++++++++++++" << '\n';
}
