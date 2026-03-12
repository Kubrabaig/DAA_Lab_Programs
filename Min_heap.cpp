#include <iostream>
using namespace std;

void heapify(int a[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && a[left] < a[smallest])
        smallest = left;

    if (right < n && a[right] < a[smallest])
        smallest = right;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        heapify(a, n, smallest);
    }
}

int main() {
    int a[] = {10, 5, 3, 2, 4};
    int n = 5;

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);

    cout << "Min Heap:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}