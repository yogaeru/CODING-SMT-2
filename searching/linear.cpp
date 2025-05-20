#include <iostream>
using std::string;

class searching {
public:
    static void linear(const int arr[], const int index, const int len) {
        bool found = false;
        for (int i = 0; i < len; i++) {
            if (index == arr[i]) {
                found = true;
                break;
            }
        }
        if (found)
            std::cout << "Data " << index << " ditemukan";
        else
            std::cout << "Data " << index << " tidak ditemukan";
    }

    void binary_search(const int arr[], const int index, const int len) {

    }
};

int main() {
    int arr[] = {4, 6, 21, 5, 78, 100};
    int len = std::size(arr);
    int index;

    std::cout << "Masukan data yang ingin dicari: ";
    std::cin >> index;
    searching::linear(arr, index, len);

    return 0;
}
