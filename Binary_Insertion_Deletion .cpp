#include <iostream>
using namespace std;

int main() {
    int a[50], n, i, key, pos = -1;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter sorted elements:\n";
    for(i = 0; i < n; i++)
        cin >> a[i];

    // Binary Search
    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(a[mid] == key) {
            pos = mid;
            break;
        }
        else if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(pos != -1)
        cout << "Element found at position " << pos + 1 << endl;
    else
        cout << "Element not found\n";

    // Insertion
    cout << "Enter element to insert: ";
    cin >> key;

    i = n - 1;
    while(i >= 0 && a[i] > key) {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = key;
    n++;

    // Deletion
    cout << "Enter element to delete: ";
    cin >> key;

    for(i = 0; i < n; i++) {
        if(a[i] == key) {
            pos = i;
            break;
        }
    }

    if(pos != -1) {
        for(i = pos; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
    }

    cout << "Final array:\n";
    for(i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}