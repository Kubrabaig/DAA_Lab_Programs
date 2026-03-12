#include <iostream>
using namespace std;

int main() {
    int a[20], n, min, pos;

    cout << "Enter number of coins: ";
    cin >> n;

    cout << "Enter weights of coins:\n";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    min = a[0];
    pos = 0;

    for(int i = 1; i < n; i++) {
        if(a[i] < min) {
            min = a[i];
            pos = i;
        }
    }

    cout << "Fake coin found at position: " << pos + 1;

    return 0;
}