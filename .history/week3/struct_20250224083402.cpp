#include <iostream>

typedef struct hitung
{
    int x, y, jml;

    void hello();
} htg;

void sayHello(const htg &d){
    d::hello(){

    }
}

int main()
{
    htg Jumlah;

    Jumlah.x = 10;
    Jumlah.y = 10;
    Jumlah.jml = Jumlah.x + Jumlah.y;
    std::cout << "Jumlah = " << Jumlah.jml << '\n';

    return 0;
}