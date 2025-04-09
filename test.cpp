#include <iostream>
#include <string>
void toBiner(int num)
{
    int biner[32];
    int temp = 0;
    if (num == 0)
        return;

    for (int i = 0; num > 0; i++)
    {
        biner[i] = num % 2;
        num /= 2;

        if (num == 0)
        {
            temp = i;
            break;
        }
    }

    int hasil[temp];

    for (int i = 0; i <= num; i++)
    {
        hasil[i] = biner[i];
    }

    // return hasil[temp];
}

int main()
{
    int a = 0b11001; // 25
    int b = a >> 3;

    std::cout << "Setelah di shift " << b << '\n';
    std::cout << 43 / 2 << '\n';
    std::cout << 43 % 2 << '\n';
    toBiner(43);
}