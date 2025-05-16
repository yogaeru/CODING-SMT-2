#include <iostream>
using namespace std;

// function to swap elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// function to print the array
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

// function to rearrange array (find the partition point)
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);

    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void merge(int array[], int start, int mid, int end) {
    int start2 = mid + 1;

    if (array[mid] <= array[start2]) {
        return;
    }

    while (start <= mid && start2 <= end) {
        if (array[start] <= array[start2]) {
            start++;
        } else {
            int value = array[start2];
            int index = start2;

            while (index != start) {
                array[index] = array[index - 1];
                index--;
            }
            array[start] = value;
            start++;
            start2++;
            mid++;
        }
    }
}

void merge_sort(int array[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

void start_merge(int array[], int len) {
    merge_sort(array, 0, len - 1);
}

int main() {
    int data[] = {5, 4, 7, 8, 2};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Unsorted Array: \n";
    printArray(data, n);
    // int len = sizeof(array) / sizeof(array[0]);

    start_merge(data, n);

    printArray(data, n);
    cout << "Sorted array in ascending order: \n";
}
