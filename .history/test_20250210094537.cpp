#include <iostream>
namespace io = std;

void addmakanan(int n);
void rendermakanan(std::string namaMakanan[100]);

int main()
{
    int n;
    io::cin >> n;
    io::cin.ignore();
    io::string namaMakanan[100];

    

   

    return 0;
}

void addmakanan(int n){
    for (int i = 0; i < n; i++)
    {
        io::getline(io::cin, namaMakanan[i]);
    }

    io::cout << "\n";
}
void rendermakanan(std::string namaMakanan[100], int n){

    for (int i=0;i<n;i++){
        io::cout << namaMakanan[i] << '\n';
    }
}
