#include <iostream>

struct Mahasiswa{
    std::string nama;
    long int nim;
};

int main(){
    int a = 5;
    int *ptr = &a;
    int **ptr2 = &ptr;


    std::cout << "Nilai a " << a << '\n';
    std::cout << "alamat a " << &a << '\n';
    std::cout << "Nilai ptr " << &ptr << '\n';
    std::cout << "Nilai ptr2 " << ptr2<<'\n';


    Mahasiswa *mhs1 = new Mahasiswa(); 
    Mahasiswa *mhs2 = new Mahasiswa[5]; 

    std::cout << mhs1 <<'\n';
    std::cout << mhs2;

    return 0;
}