#include <iostream>

int main(){
    // int n;
    // std::cin >> n;
    std::string namaMakanan[4];

    for (int i=0;i<4;i++){
        std::cin >> namaMakanan[i];
    }

    for(std::string makanan : namaMakanan){
        std::cout << " " << makanan;
    }

return 0;
}