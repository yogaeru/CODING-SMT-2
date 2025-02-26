#include <iostream>

int main(){
    int a = 5;
    int *ptr = &a;
    int **ptr2 = &ptr;


    std::cout << "Nilai a " << a << '\n';
    std::cout << "alamat a " << &a << '\n';
    std::cout << "Nilai ptr " << &ptr << '\n';
    std::cout << "Nilai ptr2 " << ptr2;


    return 0;
}