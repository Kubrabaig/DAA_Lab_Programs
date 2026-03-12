#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int i=l, j=m+1, k=0, b[50];

    while(i<=m && j<=r) {
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while(i<=m)
        b[k++] = a[i++];

    while(j<=r)
        b[k++] = a[j++];

    for(i=l, k=0; i<=r; i++, k++)
        a[i] = b[k];
}

void mergesort(int a[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[50], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i=0;i<n;i++)
        cin >> a[i];

    mergesort(a, 0, n-1);

    cout << "Sorted array:\n";
    for(int i=0;i<n;i++)
        cout << a[i] << " ";

    return 0;
}