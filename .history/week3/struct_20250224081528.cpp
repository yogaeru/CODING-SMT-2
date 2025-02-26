#include <iostream>

struct hitung
{
    int x, y, jml;
};

int main()
{
    hitung Jumlah;

    Jumlah.x = 10;
    Jumlah.y = 10;
    Jumlah.jml = Jumlah.x + Jumlah.y;
    std::cout << "Jumlah = " << Jumlah.jml << '\n';

    return 0;
}